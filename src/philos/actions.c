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
	size_t aux = philo->number % philo->amount_of_philos;
	if (check_for_dead(philo) == true)
		return ;

	while(true) {
		pthread_mutex_lock(philo->thinking);
		if (philo->forks_state[aux] == false && \
            philo->forks_state[philo->number - 1] == false) {
			phi_pick_forks(philo);
			philo->forks_state[aux] = true;
			philo->forks_state[philo->number - 1] = true;
			pthread_mutex_unlock(philo->thinking);
			break;
		} else {
			pthread_mutex_unlock(philo->thinking);
			usleep(100);
		}
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
}

void	phi_eat(t_philo *philo)
{
	if (check_for_dead(philo) == true)
	{
		unlock_forks(philo);
		return ;
	}
//	pthread_mutex_lock(&philo->writing);
	philo->last_meal = phi_time();
//	pthread_mutex_unlock(&philo->writing);
	phi_message(philo, "is eating");
	philo->meal_count++;
	usleep(philo->eat*1000);
	//phi_usleep(philo,(philo->eat));
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
		phi_eat(philo);
		unlock_forks(philo);
		phi_sleep(philo);
	}
}
