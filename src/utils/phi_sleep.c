
#include "../../include/philos.h"
#include <pthread.h>
#include <unistd.h>


void	phi_usleep(t_philo *philo, long time)
{
	int count;

	count = 0;
	pthread_mutex_lock(&philo->writing);
	while (count < 100)
	{
		if (check_for_dead(philo) == true)
		{
			unlock_forks(philo);
			pthread_mutex_unlock(&philo->writing);
			return;
		}
		usleep(time * 10);
		count++;
	}
	pthread_mutex_unlock(&philo->writing);
}
