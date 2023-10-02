/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_philos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 16:01:19 by laura         #+#    #+#                 */
/*   Updated: 2023/09/29 16:01:19 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include <pthread.h>
#include <stdlib.h>

void	free_philos(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	while (count < philos_data->amount)
	{
		pthread_mutex_destroy(&philos_data->philos[count].writing);
		free(&philos_data->philos[count]);
		count++;
	}
	free(philos_data->philos);
}

void	free_data(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	free(philos_data->thinking);
	free(philos_data->message);
	free(philos_data->end);
	while (count < philos_data->amount)
	{
		pthread_mutex_destroy(&philos_data->philos[count].writing);
		count++;
	}
	free(philos_data->cycles);
	free(philos_data->forks_state);
	free(philos_data->philos);
	free(philos_data->philo_t);
}
