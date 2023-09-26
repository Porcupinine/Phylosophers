/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:56 by laura         #+#    #+#                 */
/*   Updated: 2023/09/26 11:53:15 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "../../include/philos.h"
#include <time.h>
#include <sys/time.h>

void	phi_pick_forks(t_philo *philo)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);
//	printf("at %ld philo %d is waiting for forks\n", (tv.tv_usec - philo->start), philo->number);
	if (philo->number >= philo->amount_of_philos)
		pthread_mutex_lock(&philo->forks[0]);
	else
		pthread_mutex_lock(&philo->forks[philo->number]);
	pthread_mutex_lock(&philo->forks[(philo->number - 1)]);
	gettimeofday(&tv,&tz);
//	printf("at %ld philo %d has forks\n", (tv.tv_usec - philo->start), philo->number);
}

void	phi_eat(t_philo *philo)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);
	printf("at %ld philo %d starts eating\n", (tv.tv_usec - philo->start), philo->number);
	usleep (philo->eat);
	if (philo->number >= philo->amount_of_philos)
		pthread_mutex_unlock(&philo->forks[0]);
	else
		pthread_mutex_unlock(&philo->forks[philo->number]);
	pthread_mutex_unlock(&philo->forks[(philo->number - 1)]);
	gettimeofday(&tv,&tz);
	printf("at %ld philo %d is done eating\n", (tv.tv_usec - philo->start), philo->number);
}

void	phi_sleep(t_philo *philo)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);
//	printf("at %ld philo %d started sleep\n", (tv.tv_usec - philo->start), philo->number);
	usleep (philo->sleep);
	gettimeofday(&tv,&tz);
//	printf("at %ld philo %d woke-up\n", (tv.tv_usec - philo->start), philo->number);
}

void	*philo_routine(void *phi_data)
{
	t_philo	*philo;
	struct timeval tv;
	struct timezone tz;

	int i;
	gettimeofday(&tv, &tz);
	philo = (t_philo *) phi_data;
	philo->start = (int)tv.tv_usec;
	for (i = 0; i < 5; i++)
	{
		gettimeofday(&tv, &tz);
//		printf("at %ld philo %d says hi!\n", (tv.tv_usec - philo->start), philo->number);
		phi_pick_forks(philo);
		phi_eat(philo);
		phi_sleep(philo);
	}
	return NULL;
}
