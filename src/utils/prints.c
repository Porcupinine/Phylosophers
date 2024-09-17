/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prints.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:19:36 by laura         #+#    #+#                 */
/*   Updated: 2023/10/12 22:19:36 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include <stdio.h>

void	print_philos(t_philo *philos, size_t size)
{
	size_t	count;

	count = 0;
	while (count < size)
	{
		printf("Philo %d\nLast meal: %ld\nmeal count: %d"
			"\n----------\ncycles: %d\nlifespan: %ld\neat: %ld\n"
			"sleep: %ld\n/////////////////\n\n",
			philos[count].number, philos[count].last_meal,
			philos[count].meal_count,
			*philos[count].cycles, philos[count].lifespan,
			philos[count].eat, philos[count].sleep);
		count++;
	}
}
