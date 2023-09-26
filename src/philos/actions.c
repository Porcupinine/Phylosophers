/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:56 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:36:36 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/philos.h"

void	eat(t_philo *philo)
{
	usleep (philo->eat);
}

void	sleep(void *arg)
{
	useconds_t	*timer;

	timer = (useconds_t*)arg;
	usleep (*timer);
}

void *think(void *arg)
{

}
