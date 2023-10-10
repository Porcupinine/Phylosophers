/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 14:35:16 by laura         #+#    #+#                 */
/*   Updated: 2023/09/25 14:35:16 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <unistd.h>

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

int	thread_philos(t_philos_data *philos_data)
{
	t_philo		*aux;
	int			count;

	count = 0;
	philos_data->philo_t = ft_calloc(philos_data->amount, sizeof (pthread_t));
	if (philos_data->philo_t == NULL)
		return (1);
	while (count < philos_data->amount)
	{
		aux = philos_data->philos + count;
		if (pthread_create(philos_data->philo_t + count, NULL, \
		&philo_routine, aux) != 0)
		{
			phi_error("Failed to create thread\n");
			return (1);
		}
		count++;
	}
	check_thread(philos_data);
	if (join_philos(philos_data) == 1)
		return (1);
	return (0);
}
//TODO what to do if we fail? create, check and store thread id
