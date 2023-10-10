
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


void	phi_usleep(t_philo *philo, long time)
{
	long	goal_time;

	goal_time = phi_time() + time;

	while (phi_time() < goal_time)
	{
//		pthread_mutex_lock(philo->message);
//		printf("phi_time: %d   goal_time: %ld   time:%ld\n", phi_time(), goal_time, time);
//		pthread_mutex_unlock(philo->message);

		pthread_mutex_lock(&philo->writing);
		if (philo->my_funeral == true)
		{
			pthread_mutex_unlock(&philo->writing);
			break ;
		}
		pthread_mutex_unlock(&philo->writing);
		usleep(1000);
	}
//	pthread_mutex_lock(philo->message);
//	printf("Haroooo\n");
//	pthread_mutex_unlock(philo->message);
}
