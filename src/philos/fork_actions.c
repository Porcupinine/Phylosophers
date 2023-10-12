/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:32:38 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 22:32:38 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include <pthread.h>

void	set_forks(t_philo *philo, size_t *left, size_t *right)
{
	if (philo->number == philo->amount_of_philos)
	{
		*left = philo->number % philo->amount_of_philos;
		*right = philo->number - 1;
	}
	else
	{
		*left = philo->number - 1;
		*right = philo->number % philo->amount_of_philos;
	}
}

bool	grab_forks(t_philo *philo)
{
	size_t	left;
	size_t	right;

	set_forks(philo, &left, &right);
	pthread_mutex_lock(&(philo->forks[left]));
	if (!philo->forks_state[left])
	{
		pthread_mutex_lock(&(philo->forks[right]));
		if (!philo->forks_state[right])
		{
			philo->forks_state[left] = true;
			philo->forks_state[right] = true;
			pthread_mutex_unlock(&(philo->forks[right]));
			pthread_mutex_unlock(&(philo->forks[left]));
			return (true);
		}
		pthread_mutex_unlock(&(philo->forks[right]));
	}
	pthread_mutex_unlock(&(philo->forks[left]));
	return (false);
}
