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
	if (check_for_dead(philo) == true)
		return ;
	pthread_mutex_lock(philo->thinking);
	if (philo->number == philo->amount_of_philos && \
		philo->forks_state[0] == false && \
		philo->forks_state[philo->number - 1] == false)
	{
		phi_pick_forks(philo);
	}
	else if (philo->number < philo->amount_of_philos && \
	philo->forks_state[philo->number] == false && \
	philo->forks_state[philo->number - 1] == false)
	{
		phi_pick_forks(philo);
	}
	else
	{
		pthread_mutex_unlock(philo->thinking);
		usleep(philo->eat * 1000);
	}
}

void	phi_pick_forks(t_philo *philo)
{
	if (check_for_dead(philo) == true)
	{
		pthread_mutex_unlock(philo->thinking);
		return ;
	}
	lock_forks(philo);
	phi_message(philo, "has forks");
	pthread_mutex_unlock(philo->thinking);
	phi_eat(philo);
}

void	phi_eat(t_philo *philo)
{
	if (check_for_dead(philo) == true)
	{
		unlock_forks(philo);
		return ;
	}
	phi_message(philo, "is eating");
	philo->last_meal = phi_time();
	philo->meal_count++;
	pthread_mutex_lock(&philo->writing);
	usleep (philo->eat * 1000);
	pthread_mutex_unlock(&philo->writing);
	unlock_forks(philo);
	phi_sleep(philo);
}

void	phi_sleep(t_philo *philo)
{
	if (check_for_dead(philo) == true)
		return ;
	phi_message(philo, "is sleeping");
	usleep (philo->sleep * 1000);
	if (check_for_dead(philo) == true)
		return ;
	phi_message(philo, "is thinking");
}

void	*philo_routine(void *phi_data)
{
	t_philo	*philo;
	bool	x;

	philo = (t_philo *) phi_data;
	while (check_for_dead(philo) == false && done_meals(philo) == false)
	{
		if (dead_or_alive(philo) == true)
			break ;
		phi_wait_for_forks(philo);
	}
}
//TODO changing from true to false while anothher philo lookes for forks