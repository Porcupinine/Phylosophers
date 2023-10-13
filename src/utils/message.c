/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 13:06:54 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 13:06:54 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

void	phi_message(t_philo *philo, char *message)
{
	long	time;

	time = phi_time();
	pthread_mutex_lock(&philo->writing);
	//pthread_mutex_lock(&philo->meal_mutex);
	if (!philo->my_funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s\n", time - philo->start, philo->number, message);
		pthread_mutex_unlock(philo->message);
	}
	//pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->writing);
}

void	phi_food_message(t_philo *philo, char *message)
{
//	long	time;
//
//	time = phi_time();
	pthread_mutex_lock(&philo->writing);
	//pthread_mutex_lock(&philo->meal_mutex);
	if (!philo->my_funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s\n", philo->last_meal - philo->start, philo->number, message);
		pthread_mutex_unlock(philo->message);
	}
	//pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->writing);
}

void	phi_fork_message(t_philo *philo, char *message)
{
	long	time;

	time = phi_time();
	pthread_mutex_lock(&philo->writing);
	//pthread_mutex_lock(&philo->meal_mutex);
	if (!philo->my_funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s\n%ld %d %s\n", time - philo->start, philo->number, message,
			time - philo->start, philo->number, message);
		pthread_mutex_unlock(philo->message);
	}
	//pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->writing);
}

void	phi_attempt_message(t_philo *philo, char *message)
{
	long	time;

	time = phi_time() - philo->start;
	pthread_mutex_lock(&philo->writing);
	pthread_mutex_lock(&philo->meal_mutex);
	if (!philo->my_funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s %d\n", time, philo->number, message, \
		philo->fork_attempts);
		pthread_mutex_unlock(philo->message);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->writing);
}

void	phi_meals_message(t_philo *philo, char *message)
{
	long	time;

	time = phi_time() - philo->start;
	pthread_mutex_lock(&philo->writing);
	pthread_mutex_lock(&philo->meal_mutex);
	if (!philo->my_funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s %d\n", time, philo->number, message, \
		philo->meal_count);
		pthread_mutex_unlock(philo->message);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->writing);
}
