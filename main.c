/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:47:04 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/09/21 16:04:25 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "include/philos.h"
#include "include/utils.h"

int	main(int argc, char **argv)
{
	t_philos_data	*run;

	run = ft_calloc(1, sizeof(t_philos_data));
	if (run == NULL)
		return (1);
	if (argc < 5 || argc > 6)
	{
		phi_error("Wrong amount of arguments\n");
		return (1);
	}
	if (set_data(argc, argv, run) == 1)
	{
		phi_error("invalid data\n");
		return (1);
	}
	run->start = phi_time();
	init_mutexes(run);
	create_philos(run);
	thread_philos(run);
	if (run->funeral == true)
		printf("\nSory, someone died, we must attend a philo my_funeral\n");
	destroy_mutexes(run);
	free_data(run);
	free(run);
	return (0);
}
