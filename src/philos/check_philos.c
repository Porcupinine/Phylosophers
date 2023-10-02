/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 15:01:37 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 15:01:37 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

bool	dead_or_alive(t_philo *philo)
{
	int	current_time;

	current_time = phi_time();
	pthread_mutex_lock(philo->end);
	pthread_mutex_lock(&philo->writing);
	if ((current_time - philo->last_meal) > philo->lifespan)
	{
		*philo->funeral = true;
		phi_message(philo, "is dead");
		pthread_mutex_unlock(&philo->writing);
		pthread_mutex_unlock(philo->end);
		return (true);
	}
	pthread_mutex_unlock(&philo->writing);
	pthread_mutex_unlock(philo->end);
	return (false);
}

bool	check_for_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(philo->end);
	dead = *philo->funeral;
	pthread_mutex_unlock(philo->end);
	return (dead);
}

bool	done_meals(t_philo *philo)
{
	if (philo->cycles == NULL || philo->meal_count != *philo->cycles)
	{
		return (false);
	}
	return (true);
}