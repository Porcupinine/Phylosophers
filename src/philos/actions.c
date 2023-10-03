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

void	phi_wait_for_forks(t_philo *philo)
{
	size_t	aux;

	aux = philo->number % philo->amount_of_philos;
	while (true)
	{
		pthread_mutex_lock(philo->thinking);

		if (philo->forks_state[aux] == false && \
			philo->forks_state[philo->number - 1] == false)
		{
			philo->forks_state[aux] = true;
			philo->forks_state[philo->number - 1] = true;
			pthread_mutex_unlock(philo->thinking);
			phi_pick_forks(philo);
			break ;
		}
		else
		{
			pthread_mutex_unlock(philo->thinking);
			usleep(philo->number % 20);
		}
	}
}

void	phi_pick_forks(t_philo *philo)
{
	lock_forks(philo);
	phi_message(philo, "has forks");
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
