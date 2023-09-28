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
//	phi_message(philo, "is waiting to check on forks", philo->start);
	usleep(5);
	pthread_mutex_lock(philo->thinking);
	if (philo->number == philo->amount_of_philos && \
		philo->forks_state[0] == false && \
		philo->forks_state[philo->number - 1] == false)
	{
		phi_pick_forks(philo);
	}
	else if (philo->forks_state[philo->number] == false && \
	philo->forks_state[philo->number - 1] == false)
	{
		phi_pick_forks(philo);
	}
	else
	{
		pthread_mutex_unlock(philo->thinking);
		usleep(1000);
	}
}

void	phi_pick_forks(t_philo *philo)
{
	if (philo->number >= philo->amount_of_philos)
	{
		pthread_mutex_lock(&philo->forks[0]);
		philo->forks_state[0] = true;
	}
	else
	{
		pthread_mutex_lock(&philo->forks[philo->number]);
		philo->forks_state[philo->number] = true;
	}
	pthread_mutex_lock(&philo->forks[(philo->number - 1)]);
	philo->forks_state[(philo->number - 1)] = true;
	phi_message(philo, "has forks");
	pthread_mutex_unlock(philo->thinking);
	phi_eat(philo);
}

void	phi_eat(t_philo *philo)
{
	phi_message(philo, "is eating");
	philo->last_meal = phi_time();
	philo->meal_count++;
	pthread_mutex_lock(&philo->writing);
	usleep (philo->eat * 1000);
	pthread_mutex_unlock(&philo->writing);
	if (philo->number >= philo->amount_of_philos)
	{
		pthread_mutex_unlock(&philo->forks[0]);
		philo->forks_state[0] = false;
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[philo->number]);
		philo->forks_state[philo->number] = false;
	}
	pthread_mutex_unlock(&philo->forks[(philo->number - 1)]);
	philo->forks_state[philo->number - 1] = false;
	phi_sleep(philo);
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
	while (dead_or_alive(philo) != 1)
	{
		phi_wait_for_forks(philo);
	}
	//TODO kill all process and retunr dead philo
	return NULL;
}
