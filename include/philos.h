/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:37:49 by laura         #+#    #+#                 */
/*   Updated: 2023/09/21 16:05:21 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <sys/types.h>
#include <stdbool.h>

/**
 * @param number philo tag;
 * @param thread_id philo id;
 * @param last_meal when philo was done eating
 * @param sleep_timer when philo started slepping
 */
typedef struct s_philo
{
	bool				done_eating;
	long				start;//main
	int					number;
	pid_t				thread_id;
	long				last_meal;
	long				sleep_timer;
	int					amount_of_philos;//main
	long				eat;//main
	long				sleep;//main
	long				lifespan;//main
	int					*cycles;//main
	int					meal_count;
	pthread_mutex_t		*forks;//main
	pthread_mutex_t		*thinking;//main
	pthread_mutex_t		writing;
	pthread_mutex_t		*message;//main
	pthread_mutex_t		*end;//main
	bool				*forks_state;//main
	bool				*funeral;//main
}t_philo;

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
	long				start;
	int					amount;
	long				lifespan;
	long				eat;
	long				sleep;
	int					*cycles;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*thinking;
	pthread_mutex_t		*message;
	pthread_mutex_t		*end;
	bool				*forks_state;
	bool				funeral;
	pthread_t			*philo_t;
}t_philos_data;

int		set_data(int argc, char **argv, t_philos_data *run);
int		create_philos(t_philos_data *philos_data);
int		thread_philos(t_philos_data *philos_data);
int		init_mutexes(t_philos_data *philos_data);
void	destroy_mutexes(t_philos_data *philos_data);
int		create_forks(t_philos_data *philos_data);
void	*philo_routine(void *philo_data);
void	phi_pick_forks(t_philo *philo);
void	phi_eat(t_philo *philo);
void	phi_sleep(t_philo *philo);
bool	dead_or_alive(t_philo *philo);
void	free_data(t_philos_data *philos_data);
void	lock_forks(t_philo *philo);
void	unlock_forks(t_philo *philo);
bool	check_for_dead(t_philo *philo);
bool	done_meals(t_philo *philo);
void	check_thread(t_philos_data *philos_data);

#endif //PHILOS_H
