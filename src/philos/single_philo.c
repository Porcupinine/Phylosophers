/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:03:51 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 11:03:51 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include "../../include/utils.h"


void	*single_philo_routine(void *phi_data)
{
	t_philo	*philo;

	philo = (t_philo *) phi_data;
	phi_message(philo, "has taken a fork");
	phi_usleep(philo, philo->lifespan);
	return (NULL);
}