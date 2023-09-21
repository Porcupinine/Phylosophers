/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:37:49 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:38:08 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

#include <sys/types.h>

/**
 * @param amount amount of philos sharing the pasta (and amoun of forks)
 * @param lifespan how long a philo can leave without food
 * @param eat how long it takes for a philo to be full and ready to sleep
 * @param sleep how long a philo takes to recharge its batteries
 * @param cycles (optional) how many times each philo should eat before we
 * are done
 */
typedef struct s_philos_data
{
	int	amount;
	int	lifespan;
	int	eat;
	int	sleep;
	int	cycles;
}t_philos_data;

typedef struct s_philo
{
	int		number;
	pid_t	thread_id;
	int		last_meal;
	int		sleep_timer;
}t_philo;

int	set_data(int argc, char **argv, t_philos_data *run);

#endif //PHILOS_H
