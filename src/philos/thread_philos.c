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

int	thread_philos(t_philos_data *philos_data)
{
	pthread_t	*philo;
	t_philo		*aux;
	int			count;

	count = 0;
	philo = ft_calloc(philos_data->amount, sizeof (pthread_t));
	if (philo == NULL)
		return (1);
	while (count < philos_data->amount)
	{
		aux = philos_data->philos + count;
		if (pthread_create(philo + count, NULL, \
		&philo_routine, aux) != 0)
		{
			phi_error("Failed to create thread\n");
			return (1);
		}
		count++;
	}
	count = 0;
	while (count < philos_data->amount)
	{
		if (pthread_join(philo[count], NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}
//TODO what to do if we fail?
