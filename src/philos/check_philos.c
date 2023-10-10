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

bool	dead_or_alive(t_philo *philo, t_philos_data *philos_data)
{
	long	current_time;

	current_time = phi_time();
	pthread_mutex_lock(&philo->writing);
	if ((current_time - philo->last_meal) > philo->lifespan && \
	philo->done_eating == false)
	{
		philo->my_funeral = true;
		int count = 0;
		while (count < philos_data->amount)
		{
			if (&philos_data->philos[count] == philo)
			{
				count++;
				continue ;
			}
			pthread_mutex_lock(&philos_data->philos[count].writing);
			philos_data->philos[count].my_funeral = true;
			pthread_mutex_unlock(&philos_data->philos[count].writing);
			count++;
		}
		pthread_mutex_lock(philo->message);
		printf("%ld %d is dead\n", current_time - philo->start, philo->number);
		pthread_mutex_unlock(philo->message);
		pthread_mutex_unlock(&philo->writing);
		return (true);
	}
	pthread_mutex_unlock(&philo->writing);
	return (false);
}//TODO make their own mutex to check change their own status and check status, will it make it quicker ??


bool	check_for_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(&philo->writing);
	dead = philo->my_funeral;
	pthread_mutex_unlock(&philo->writing);
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

void	all_fed(t_philos_data *philos_data)
{
	int count;

	count = 0;
	while (count < philos_data->amount)
	{
		pthread_mutex_lock(&philos_data->philos[count].writing);
		philos_data->philos[count].all_fed = true;
		pthread_mutex_unlock(&philos_data->philos[count].writing);
		count++;
	}
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
		while (count < philos_data->amount)
		{
			ok = dead_or_alive(&philos_data->philos[count], philos_data);
			if (done_meals(&philos_data->philos[count]) == false)
				eating = true;
			if (ok == true)
				break ;
			count++;
		}
		if (eating == false)
		{
			all_fed(philos_data);
			break ;
		}
		eating = false;
		usleep(900);
	}
}