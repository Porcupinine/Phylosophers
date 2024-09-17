/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 15:23:59 by laura         #+#    #+#                 */
/*   Updated: 2023/09/25 15:23:59 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

static void	destroy_forks(t_philos_data *philos_data, int count)
{
	while (count >= 0)
	{
		pthread_mutex_destroy(&philos_data->forks[count]);
		count--;
	}
	free (philos_data->forks);
}

int	create_forks(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	philos_data->forks = ft_calloc(philos_data->amount, \
	sizeof (pthread_mutex_t));
	if (philos_data->forks == NULL)
		return (1);
	philos_data->forks_state = ft_calloc(philos_data->amount, \
	sizeof (bool));
	if (philos_data->forks_state == NULL)
		return (1);
	while (count < philos_data->amount)
	{
		if (pthread_mutex_init(&philos_data->forks[count], NULL) != 0)
		{
			destroy_forks(philos_data, count);
			return (1);
		}
		philos_data->forks_state[count] = false;
		count++;
	}
	return (0);
}

int	init_mutexes(t_philos_data *philos_data)
{
	philos_data->message = ft_calloc(1, sizeof (pthread_mutex_t));
	if (philos_data->message == NULL)
		return (1);
	pthread_mutex_init(philos_data->message, NULL);
	if (create_forks(philos_data) == 1)
		return (1);
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->forks[philo->l_fork_position]));
	philo->forks_state[philo->l_fork_position] = false;
	pthread_mutex_unlock(&(philo->forks[philo->l_fork_position]));
	pthread_mutex_lock(&(philo->forks[philo->r_fork_position]));
	philo->forks_state[philo->r_fork_position] = false;
	pthread_mutex_unlock(&(philo->forks[philo->r_fork_position]));
}

