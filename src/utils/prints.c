//
// Created by lpraca-l on 9/21/23.
//

#include "../../include/philos.h"
#include <stdio.h>

void	print_philos(t_philo *philos, size_t size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		printf("Philo %d\nID: %d\nLast meal: %d\nLast sleep: %d\n----------\n",
			   philos[count].number, philos[count].thread_id, philos[count].last_meal,
			   philos[count].sleep_timer);
		count++;
	}
}