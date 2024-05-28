/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 14:35:16 by laura         #+#    #+#                 */
/*   Updated: 2023/10/26 23:22:28 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <unistd.h>
#include "../../include/check.h"

static void	thread_creation_fail(t_philos_data *philos_data, int count)
{
	int	x;

	x = 0;
	*philos_data->error = true;
	pthread_mutex_unlock(philos_data->start_mut);
	while (x < count)
	{
		pthread_join(philos_data->philo_t[x], NULL);
		x++;
	}
}

static int	join_philos(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	while (count < philos_data->amount)
	{
		if (pthread_join(philos_data->philo_t[count], NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}

static int	thread_single_philo(t_philos_data *philos_data)
{
	t_philo		*aux;
	int			count;

	count = 0;
	philos_data->philo_t = ft_calloc(philos_data->amount, sizeof (pthread_t));
	if (philos_data->philo_t == NULL)
		return (1);
	aux = philos_data->philos + count;
	if (pthread_create(philos_data->philo_t + count, NULL, \
	&single_philo_routine, aux) != 0)
	{
		thread_creation_fail(philos_data, count);
		phi_error("Failed to create thread\n");
		return (1);
	}
	return (0);
}

static int	thread_multi_philo(t_philos_data *philos_data)
{
	t_philo		*aux;
	int			count;

	count = 0;
	philos_data->philo_t = ft_calloc(philos_data->amount, sizeof (pthread_t));
	if (philos_data->philo_t == NULL)
		return (1);
	pthread_mutex_lock(philos_data->start_mut);
	while (count < philos_data->amount)
	{
		aux = philos_data->philos + count;
		if (pthread_create(philos_data->philo_t + count, NULL, \
		&philo_routine, aux) != 0)
		{
			thread_creation_fail(philos_data, count);
			phi_error("Failed to create thread\n");
			return (1);
		}
		count++;
	}
	pthread_mutex_unlock(philos_data->start_mut);
	return (0);
}

int	thread_philos(t_philos_data *philos_data)
{
	*(philos_data->start) = phi_time();
	if (philos_data->amount == 1)
	{
		if (thread_single_philo(philos_data) == 1)
			return (1);
	}
	else
	{
		if (thread_multi_philo(philos_data) == 1)
			return (1);
	}
	check_thread(philos_data);
	if (join_philos(philos_data) == 1)
		return (1);
	return (0);
}
