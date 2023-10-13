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

void	set_forks(t_philo *philo)
{
	int	right;
	int	left;

	if (philo->number == philo->amount_of_philos)
	{
		left = philo->number % philo->amount_of_philos;
		right = philo->number - 1;
	}
	else
	{
		left = philo->number - 1;
		right = philo->number % philo->amount_of_philos;
	}
	philo->l_fork_position = left;
	philo->r_fork_position = right;
}

bool	grab_forks(t_philo *philo)
{

	pthread_mutex_lock(&(philo->forks[philo->l_fork_position]));
	if (!philo->forks_state[philo->l_fork_position])
	{
		pthread_mutex_lock(&(philo->forks[philo->r_fork_position]));
		if (!philo->forks_state[philo->r_fork_position])
		{
			philo->forks_state[philo->l_fork_position] = true;
			philo->forks_state[philo->r_fork_position] = true;
			pthread_mutex_unlock(&(philo->forks[philo->r_fork_position]));
			pthread_mutex_unlock(&(philo->forks[philo->l_fork_position]));
			return (true);
		}
		pthread_mutex_unlock(&(philo->forks[philo->r_fork_position]));
	}
	pthread_mutex_unlock(&(philo->forks[philo->l_fork_position]));
	return (false);
}
