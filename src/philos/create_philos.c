/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 14:35:45 by laura         #+#    #+#                 */
/*   Updated: 2023/09/25 14:35:45 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include "../../include/utils.h"
#include <sys/time.h>
#include <pthread.h>

static void	set_philo(t_philos_data *philos_data)
{
	int	count;

	count = 1;
	while (count <= philos_data->amount)
	{
		philos_data->philos[count - 1].number = count;
		philos_data->philos[count - 1].forks = philos_data->forks;
		philos_data->philos[count - 1].cycles = philos_data->cycles;
		philos_data->philos[count - 1].eat = philos_data->eat;
		philos_data->philos[count - 1].sleep = philos_data->sleep;
		philos_data->philos[count - 1].lifespan = philos_data->lifespan;
		philos_data->philos[count - 1].amount_of_philos = philos_data->amount;
		philos_data->philos[count - 1].start = philos_data->start;
		philos_data->philos[count - 1].forks_state = philos_data->forks_state;
		philos_data->philos[count - 1].thinking = philos_data->thinking;
		pthread_mutex_init(&philos_data->philos[count - 1].writing, NULL);
		philos_data->philos[count - 1].message = philos_data->message;
		philos_data->philos[count - 1].my_funeral = false;
		philos_data->philos[count - 1].end = philos_data->end;
		philos_data->philos[count - 1].last_meal = philos_data->start;
		philos_data->philos[count - 1].done_eating = false;
		philos_data->philos[count - 1].fork_attempts = 0;
		count++;
	}
}

int	create_philos(t_philos_data *philos_data)
{
	philos_data->philos = ft_calloc((philos_data->amount + 1), \
	sizeof (t_philo));
	if (philos_data->philos == NULL)
		return (1);
	philos_data->funeral = false;
	set_philo(philos_data);
	return (0);
	//TODO track fail
}
