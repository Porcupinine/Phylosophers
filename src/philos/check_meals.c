/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_meals.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 13:33:04 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 13:33:04 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include <pthread.h>

bool	done_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->writing);
	if (philo->cycles == NULL || philo->meal_count != *philo->cycles)
	{
		pthread_mutex_unlock(&philo->writing);
		return (false);
	}
	philo->done_eating = true;
	pthread_mutex_unlock(&philo->writing);
	return (true);
}

void	all_fed(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	while (count < philos_data->amount)
	{
		pthread_mutex_lock(&philos_data->philos[count].writing);
		philos_data->philos[count].all_fed = true;
		pthread_mutex_unlock(&philos_data->philos[count].writing);
		count++;
	}
}
