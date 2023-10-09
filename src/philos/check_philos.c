/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 15:01:37 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 15:01:37 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <unistd.h>

bool	dead_or_alive(t_philo *philo)
{
	long	current_time;

	current_time = phi_time();
	pthread_mutex_lock(philo->end);
	pthread_mutex_lock(&philo->writing);
	if ((current_time - philo->last_meal) > philo->lifespan && \
	philo->done_eating == false)
	{
		*philo->funeral = true;
		pthread_mutex_lock(philo->message);
		printf("%ld %d is dead\n", phi_time() - philo->start, philo->number);
		pthread_mutex_unlock(philo->message);
		pthread_mutex_unlock(&philo->writing);
		pthread_mutex_unlock(philo->end);
		return (true);
	}
	pthread_mutex_unlock(&philo->writing);
	pthread_mutex_unlock(philo->end);
	return (false);
}//TODO make their own mutex to check change their own status and check status, will it make it quicker ??


bool	check_for_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(philo->end);
	dead = *philo->funeral;
	pthread_mutex_unlock(philo->end);
	return (dead);
}

bool	done_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->writing);
	if (philo->cycles == NULL || philo->meal_count != *philo->cycles)
	{
		pthread_mutex_unlock(&philo->writing);
		return (false);
	}
	philo->done_eating = true;
	pthread_mutex_unlock(&philo->writing);
	return (true);
}

void	check_thread(t_philos_data *philos_data)
{
	int		count;
	bool	ok;
	bool	eating;

	eating = false;
	ok = false;
	while (ok == false)
	{
		count = 0;
//		pthread_mutex_lock(philos_data->end);
		while (count < philos_data->amount)
		{
			ok = dead_or_alive(&philos_data->philos[count]);
			if (!philos_data->philos[count].done_eating)
				eating = true;
			if (ok == true)
				break ;
			count++;
		}
//		pthread_mutex_unlock(philos_data->end);
		if (!eating)
			break ;
		usleep(900);
	}
}