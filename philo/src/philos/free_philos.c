/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_philos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 16:01:19 by laura         #+#    #+#                 */
/*   Updated: 2023/10/30 13:20:23 by lpraca-l      ########   odam.nl         */
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
		pthread_mutex_destroy(&philos_data->philos[count].meal_mutex);
		count++;
	}
	free(philos_data->philos);
}

void	free_twenty_five(t_philos_data *philos_data)
{
	free(philos_data->start);
	free(philos_data->error);
	free(philos_data->forks_state);
}

void	free_data(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	free(philos_data->cycles);
	if (philos_data->message != NULL)
	{
		pthread_mutex_destroy(philos_data->message);
		free(philos_data->message);
	}
	if (philos_data->start_mut != NULL)
	{
		pthread_mutex_destroy(philos_data->start_mut);
		free(philos_data->start_mut);
	}
	if (philos_data->forks != NULL)
	{
		while (count < philos_data->amount)
		{
			pthread_mutex_destroy(&philos_data->forks[count]);
			count++;
		}
		free(philos_data->forks);
	}
	free_twenty_five(philos_data);
}
