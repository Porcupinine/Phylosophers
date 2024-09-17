/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phi_sleep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:17:49 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 22:17:49 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include "../../include/utils.h"
#include <pthread.h>
#include <unistd.h>

void	phi_usleep(t_philo *philo, long time)
{
	long	goal_time;

	goal_time = phi_time() + time;
	while (phi_time() < goal_time)
	{
		pthread_mutex_lock(&philo->writing);
		if (philo->my_funeral == true)
		{
			pthread_mutex_unlock(&philo->writing);
			break ;
		}
		pthread_mutex_unlock(&philo->writing);
		usleep(1000);
	}
}
