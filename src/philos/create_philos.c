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

static void	destroy_philo_mutex(t_philos_data *philos_data, int count)
{
	while (count >= 0)
	{
		pthread_mutex_destroy(&philos_data->philos[count - 1].writing);
		count--;
	}
}

static void	copy_data(t_philos_data *philos_data, const int count)
{
	philos_data->philos[count].start = philos_data->start;
	philos_data->philos[count].amount_of_philos = philos_data->amount;
	philos_data->philos[count].eat = philos_data->eat;
	philos_data->philos[count].sleep = philos_data->sleep;
	philos_data->philos[count].lifespan = philos_data->lifespan;
	philos_data->philos[count].cycles = philos_data->cycles;
	philos_data->philos[count].forks = philos_data->forks;
	philos_data->philos[count].message = philos_data->message;
	philos_data->philos[count].forks_state = philos_data->forks_state;
}
//TODO free start
static int	set_philo(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	while (count <= philos_data->amount)
	{
		copy_data(philos_data, count);
		philos_data->philos[count].number = count + 1;
		if (pthread_mutex_init(&philos_data->philos[count].writing, \
		NULL) != 0)
		{
			destroy_philo_mutex(philos_data, count);
			return (1);
		}
		if (pthread_mutex_init(&philos_data->philos[count].meal_mutex, \
		NULL) != 0)
		{
			destroy_philo_mutex(philos_data, count);
			return (1);
		}
		philos_data->philos[count].my_funeral = false;
		philos_data->philos[count].last_meal = phi_time(); //TODO errrr...
		philos_data->philos[count].done_eating = false;
		philos_data->philos[count].fork_attempts = 0;
		set_forks(&philos_data->philos[count]);
		count++;
	}
	return (0);
}

int	create_philos(t_philos_data *philos_data)
{
	philos_data->philos = ft_calloc((philos_data->amount + 1), \
	sizeof (t_philo));
	if (philos_data->philos == NULL)
		return (1);
	if (set_philo(philos_data) == 1)
		return (1);
	return (0);
}
