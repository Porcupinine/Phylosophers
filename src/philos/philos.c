/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:27 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:35:51 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/philos.h"
#include "../../include/utils.h"
#include "../../include/check.h"

int	check_limits(char **argv)
{
	if (check_int_limits(argv[1]) == 1)
		return (1);
	if (check_int_limits(argv[2]) == 1)
		return (1);
	if (check_int_limits(argv[3]) == 1)
		return (1);
	if (check_int_limits(argv[4]) == 1)
		return (1);
	return (0);
}

int	check_signal(char **argv)
{
	if (phi_atoi(argv[1]) < 0)
		return (1);
	if (phi_atoi(argv[2]) < 0)
		return (1);
	if (phi_atoi(argv[3]) < 0)
		return (1);
	if (phi_atoi(argv[4]) < 0)
		return (1);
	return (0);
}

int	set_data(int argc, char **argv, t_philos_data *run)
{
	if (check_limits(argv) == 1)
		return (1);
	if (check_signal(argv) == 1)
		return (1);
	run->amount = phi_atoi(argv[1]);
	run->lifespan = phi_atoi(argv[2]);
	run->eat = phi_atoi(argv[3]);
	run->sleep = phi_atoi(argv[4]);
	if (argc > 5)
	{
		if (check_int_limits(argv[5]) == 1 || phi_atoi(argv[5]) < 0)
			return (1);
		run->cycles = ft_calloc(1, sizeof (int));
		if (run->cycles == NULL)
			return (2);
		*run->cycles = phi_atoi(argv[5]);
	}
	return (0);
}
