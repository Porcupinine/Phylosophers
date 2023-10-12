/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_life.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 13:35:51 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 13:35:51 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include "../../include/utils.h"
#include <pthread.h>
#include <stdio.h>

void	going_to_funeral(t_philo *philo, t_philos_data *philos_data)
{
	int	count;

	count = 0;
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
}

bool	dead_or_alive(t_philo *philo, t_philos_data *philos_data)
{
	long	current_time;

	current_time = phi_time();
	pthread_mutex_lock(&philo->writing);
	if ((current_time - philo->last_meal) > philo->lifespan && \
	philo->done_eating == false)
	{
		philo->my_funeral = true;
		going_to_funeral(philo, philos_data);
		pthread_mutex_lock(philo->message);
		printf("%ld %d is dead\n", current_time - philo->start, \
		philo->number);
		pthread_mutex_unlock(philo->message);
		pthread_mutex_unlock(&philo->writing);
		return (true);
	}
	pthread_mutex_unlock(&philo->writing);
	return (false);
}

bool	check_for_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(&philo->writing);
	dead = philo->my_funeral;
	pthread_mutex_unlock(&philo->writing);
	return (dead);
}
