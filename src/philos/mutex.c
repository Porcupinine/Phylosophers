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
#include <unistd.h>
#include <stdio.h>
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
	while (count < philos_data->amount)
	{
		pthread_mutex_init(&philos_data->forks[count], NULL);
		philos_data->forks_state[count] = false;
		count++;
	}
	return (0);
}

int	init_mutexes(t_philos_data *philos_data)
{
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
	if (create_forks(philos_data) == 1)
		return (1);
	return (0);
}

void	destroy_mutexes(t_philos_data *philos_data)
{
	int	count;

	count = 0;
	pthread_mutex_destroy(philos_data->thinking);
	pthread_mutex_destroy(philos_data->message);
	pthread_mutex_destroy(philos_data->end);
	while (count < philos_data->amount)
	{
		pthread_mutex_destroy(&philos_data->forks[count]);
		count++;
	}
	free (philos_data->forks);
}

void	lock_forks(t_philo *philo)
{
	int	aux;

	aux = philo->number % philo->amount_of_philos;
	if (aux < philo->number)
	{
		pthread_mutex_lock(&(philo->forks[aux]));
		pthread_mutex_lock(&(philo->forks[(philo->number - 1)]));
	}
	else
	{
		pthread_mutex_lock(&(philo->forks[(philo->number - 1)]));
		pthread_mutex_lock(&(philo->forks[aux]));
	}
}

void	unlock_forks(t_philo *philo)
{
	size_t	aux;

	aux = philo->number % philo->amount_of_philos;
	pthread_mutex_unlock(&(philo->forks[aux]));
	pthread_mutex_unlock(&(philo->forks[philo->number - 1]));

	// TODO check philo dead
	pthread_mutex_lock(philo->thinking);
	philo->forks_state[aux] = false;
	philo->forks_state[philo->number - 1] = false;
	pthread_mutex_unlock(philo->thinking);
}

//void	lock_forks(t_philo *philo)
//{
//	if (philo->number >= philo->amount_of_philos)
//	{
//		philo->forks_state[0] = true;
//	}
//	else
//	{
//		philo->forks_state[philo->number] = true;
//	}
//	philo->forks_state[(philo->number - 1)] = true;
//	pthread_mutex_unlock(philo->thinking);
//}
//
//void	unlock_forks(t_philo *philo)
//{
//	pthread_mutex_lock(philo->thinking);
//	if (philo->number >= philo->amount_of_philos)
//		philo->forks_state[0] = false;
//	else
//		philo->forks_state[philo->number] = false;
//	philo->forks_state[philo->number - 1] = false;
//	pthread_mutex_unlock(philo->thinking);
//}
