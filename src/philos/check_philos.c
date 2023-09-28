/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 15:01:37 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 15:01:37 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

int	dead_or_alive(t_philo *philo)
{
	int	current_time;

	current_time = phi_time();
	pthread_mutex_lock(&philo->writing);
	if ((current_time - philo->last_meal) > philo->lifespan)
	{
		phi_message(philo, "is dead");
		return (1);
	}
	pthread_mutex_unlock(&philo->writing);
	return (0);
}