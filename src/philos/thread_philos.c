//
// Created by lpraca-l on 9/21/23.
//

#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

int	thread_philos(t_philos_data *philos_data)
{
	pthread_t	philo[philos_data->amount];
	int count;

	count = 0;
	while (count < philos_data->amount)
	{
		if(pthread_create(philo + count, NULL, &func, &philos_data->philos[count]) != 0)
		{
			phi_error("Failed to create thread\n");
			return (1);
		}
		count++;
	}
	count = 0;
	while (count < philos_data->amount)
	{
		if(pthread_join(philo[count], NULL) != 0)
			return (1);
		count++;
	}
	return (0);
}