
#include "../../include/philos.h"
#include <pthread.h>
#include <unistd.h>


void	phi_usleep(t_philo *philo, long time)
{
	int	count;

	count = 0;
	while (count < 100)
	{
//		pthread_mutex_lock(philo->end);
//		if (check_for_dead(philo) == true)
//		{
//			pthread_mutex_unlock(philo->end);
//			return ;
//		}
//		pthread_mutex_unlock(philo->end);
		usleep(time * 10);
		count++;
	}
}
