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

static void	mutex_init_fail(t_philos_data *run)
{
	free_data(run);
}

static void	creat_philo_fail(t_philos_data *run)
{
	free_data(run);
	free(run->philos);
}

static void	threads_fail(t_philos_data *run)
{
	free_data(run);
	free_philos(run);
	if (run->philo_t != NULL)
		free(run->philo_t);
}

static int	set_table(t_philos_data *table)
{
	if (init_mutexes(table) == 1)
	{
		mutex_init_fail(table);
		return (1);
	}
	if (create_philos(table) == 1)
	{
		creat_philo_fail(table);
		return (1);
	}
	if (thread_philos(table) == 1)
	{
		threads_fail(table);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philos_data	*table;

	table = ft_calloc(1, sizeof(t_philos_data));
	if (table == NULL)
		return (1);
	if (argc < 5 || argc > 6)
		return (phi_error("Wrong amount of arguments\n"), 1);
	if (set_data(argc, argv, table) == 1)
		return (phi_error("invalid data\n"), 1);
	table->start = phi_time();
	if (set_table(table) == 1)
	{
		free(table);
		return (1);
	}
	free_data(table);
	free_philos(table);
	free(table->philo_t);
	free(table);
	return (0);
}
