/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:56 by laura         #+#    #+#                 */
/*   Updated: 2023/10/11 17:58:14 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <sys/time.h>
#include "../../include/check.h"

static void	phi_wait_for_forks(t_philo *philo)
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

static void	phi_eat(t_philo *philo)
{
	long	time;

	time = phi_time();
	pthread_mutex_lock(&philo->writing);
	philo->last_meal = time;
	pthread_mutex_unlock(&philo->writing);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
	phi_food_message(philo, "is eating");
	phi_usleep(philo, philo->eat);
}

static void	phi_sleep(t_philo *philo)
{
	phi_message(philo, "is sleeping");
	phi_usleep (philo, philo->sleep);
	phi_message(philo, "is thinking");
	if (philo->amount_of_philos % 2 != 0)
		usleep(philo->lifespan * 100);
}

void	*philo_routine(void *phi_data)
{
	t_philo	*philo;

	philo = (t_philo *) phi_data;
//	if (philo->amount_of_philos == 2 && philo->number == 2)
//		usleep(philo->eat);
	if (philo->number % 2 == 0)
		usleep(philo->eat * 100);
//	philo->last_meal = phi_time();
	while (check_for_dead(philo) == false && philo->all_fed == false)
	{
		phi_wait_for_forks(philo);
		phi_eat(philo);
		unlock_forks(philo);
		phi_sleep(philo);
	}
	return (NULL);
}
