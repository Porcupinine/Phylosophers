
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <pthread.h>
#include <unistd.h>


void	phi_usleep(long time)
{
	int		count;
	long	goal_time;

	goal_time = phi_time() + time;

	count = 0;
	while (phi_time() < goal_time)
	{
		usleep(1000);
		count++;
	}
}
