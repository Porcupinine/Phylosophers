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
#include "../../include/philos.h"
#include "../../include/utils.h"

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
	philos_data->thinking = ft_calloc(1, sizeof (pthread_mutex_t));
	if (philos_data->thinking == NULL)
		return (1);
	pthread_mutex_init(philos_data->thinking, NULL);
	philos_data->message = ft_calloc(1, sizeof (pthread_mutex_t));
	if (philos_data->message == NULL)
		return (1);
	pthread_mutex_init(philos_data->message, NULL);
	philos_data->end = ft_calloc(1, sizeof (pthread_mutex_t));
	if (philos_data->end == NULL)
		return (1);
	pthread_mutex_init(philos_data->end, NULL);
	while (count < philos_data->amount)
	{
		pthread_mutex_init(&philos_data->forks[count], NULL);
		philos_data->forks_state[count] = false;
		count++;
	}
	return (0);
}
//TODO fail