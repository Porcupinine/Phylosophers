/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 15:01:37 by laura         #+#    #+#                 */
/*   Updated: 2023/10/11 18:01:54 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include <unistd.h>
#include "../../include/check.h"

void	check_thread(t_philos_data *philos_data)
{
	int		count;
	bool	ok;
	bool	eating;

	eating = false;
	ok = false;
	while (ok == false)
	{
		count = 0;
		while (count < philos_data->amount)
		{
			ok = dead_or_alive(&philos_data->philos[count], philos_data);
			if (done_meals(&philos_data->philos[count]) == false)
				eating = true;
			if (ok == true)
				break ;
			count++;
		}
		if (eating == false)
			return (all_fed(philos_data));
		eating = false;
		usleep(900);
	}
}
