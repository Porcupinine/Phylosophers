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
			phi_message(philo, "has forks");
			return (true);
		}
		pthread_mutex_unlock(&(philo->forks[right]));
	}
	pthread_mutex_unlock(&(philo->forks[left]));
	return (false);
}

void	phi_wait_for_forks(t_philo *philo)
{
	size_t	left;
	size_t	right;

	left = philo->number - 1;
	right = philo->number % philo->amount_of_philos;
//	size_t	left, right;
//	left = philo->number - 1;
//	right = philo->number % philo->amount_of_philos;
//	bool pegou_garfo = false;
	while (true)
	{
//		pthread_mutex_lock(&(philo->forks[left]));
//		if (!philo->forks_state[left])
//		{
//			pthread_mutex_lock(&(philo->forks[right]));
//			if(!philo->forks_state[right])
//			{
//				philo->forks_state[left] = philo->forks_state[right] = true;
//				pegou_garfo = true;
//				phi_message(philo, "has forks");
//			}
//			pthread_mutex_unlock(&(philo->forks[right]));
//		}
//		pthread_mutex_unlock(&(philo->forks[left]));
		if (grab_forks(philo) == true)
		{
			pthread_mutex_unlock(&(philo->forks[right]));
			pthread_mutex_unlock(&(philo->forks[left]));
			break ;
		}
		usleep(10);
	}

}

void	phi_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->end);
	philo->last_meal = phi_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->end);
	phi_message(philo, "is eating");
	usleep(philo->eat * 1000);
}

void	phi_sleep(t_philo *philo)
{
	phi_message(philo, "is sleeping");
	usleep (philo->sleep * 1000);
	phi_message(philo, "is thinking");
}

void	*philo_routine(void *phi_data)
{
	t_philo	*philo;

	philo = (t_philo *) phi_data;
	while (check_for_dead(philo) == false && done_meals(philo) == false)
	{
		phi_wait_for_forks(philo);
		phi_eat(philo);
		unlock_forks(philo);
		phi_sleep(philo);
	}
	return (NULL);
}
