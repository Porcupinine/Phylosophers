/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:56 by laura         #+#    #+#                 */
/*   Updated: 2023/09/26 11:53:15 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <sys/time.h>

static bool	grab_forks(t_philo *philo)
{
	size_t	left;
	size_t	right;


	left = philo->number - 1;
	right = philo->number % philo->amount_of_philos;
	pthread_mutex_lock(&(philo->forks[left]));
	if (!philo->forks_state[left])
	{
		pthread_mutex_lock(&(philo->forks[right]));
		if (!philo->forks_state[right])
		{
			philo->forks_state[left] = true;
			philo->forks_state[right] = true;
			pthread_mutex_unlock(&(philo->forks[right]));
			pthread_mutex_unlock(&(philo->forks[left]));
			return (true);
		}
		pthread_mutex_unlock(&(philo->forks[right]));
	}
	pthread_mutex_unlock(&(philo->forks[left]));
	return (false);
}

void	phi_wait_for_forks(t_philo *philo)
{
	while (true)
	{
		if (philo->fork_attempts != 0)
			usleep((philo->lifespan / 100) / philo->fork_attempts);
		if (grab_forks(philo) == true)
		{
			phi_fork_message(philo, "has taken a fork");
			philo->fork_attempts = 0;
			break ;
		}
		philo->fork_attempts++;
	}
}

void	phi_eat(t_philo *philo)
{
	long	time;

	time = phi_time();
	pthread_mutex_lock(&philo->writing);
	philo->last_meal = time;
	philo->meal_count++;
	pthread_mutex_unlock(&philo->writing);
	phi_message(philo, "is eating");
	usleep(philo->eat * 1000);
//	phi_usleep(philo, philo->eat * 1000);
}

void	phi_sleep(t_philo *philo)
{
	phi_message(philo, "is sleeping");
	usleep(philo->sleep * 1000);
//	phi_usleep (philo, philo->sleep * 1000);
	phi_message(philo, "is thinking");
	usleep(philo->lifespan * 100);
}

void	*philo_routine(void *phi_data)
{
	t_philo	*philo;

	philo = (t_philo *) phi_data;
	while (check_for_dead(philo) == false && philo->all_fed == false)
	{
		phi_wait_for_forks(philo);
		phi_eat(philo);
		unlock_forks(philo);
		phi_sleep(philo);
	}
	return (NULL);
}
