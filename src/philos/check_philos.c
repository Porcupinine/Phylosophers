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
	if ((current_time - philo->last_meal) > philo->lifespan)
	{
		*philo->funeral = true;
		pthread_mutex_lock(philo->message);
		printf("current time: %ld ---- last meal: %ld\n%ld %d is dead\n",current_time, philo->last_meal,  phi_time() - philo->start, philo->number);
		pthread_mutex_unlock(philo->message);
		pthread_mutex_unlock(philo->end);
		return (true);
	}
	pthread_mutex_unlock(philo->end);
	return (false);
}

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
	if (philo->cycles == NULL || philo->meal_count != *philo->cycles)
	{
		return (false);
	}
	return (true);
}

void	check_thread(t_philos_data *philos_data)
{
	int		count;
	bool	ok;

	ok = false;
	count = 0;
	while (ok == false)
	{
		count = 0;
		while (count < philos_data->amount)
		{
			ok = dead_or_alive(&philos_data->philos[count]);
			if (ok == true)
				break ;
			count++;
		}
		usleep(9000);
	}
}