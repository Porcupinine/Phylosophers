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
# include <stdbool.h>

/**
 * @param all_fed true if all philos had enough food
 * @param fork_attempts incremented everytime that a philo fails
 * to pick its forks, before new atempt philo will sleep based on
 * how many attempts it has made before, the more it trys the less
 * it sleeps
 * @param done_eating personal full philo flag
 * @param writing personal philo mutex to write last_meal and meal_count
 * also used to check if given philo is alive or if it is full
 * @param my_funeral personal bool is set to true in case any philo dies
 *
\ */
typedef struct s_philo
{
	bool				all_fed;
	int					fork_attempts;
	bool				done_eating;
	int					number;
	long				last_meal;
	pthread_mutex_t		writing;
	pthread_mutex_t		meal_mutex;
	bool				my_funeral;
	int					meal_count;
	int					amount_of_philos;
	long				eat;
	long				sleep;
	long				lifespan;
	int					*cycles;
	long				*start;
	int					l_fork_position;
	int					r_fork_position;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	bool				*forks_state;
}t_philo;

/**
 * @param amount amount of philos sharing the pasta (and amoun of forks)
 * @param lifespan how long a philo can leave without food
 * @param eat how long it takes for a philo to be full and ready to sleep
 * @param sleep how long a philo takes to recharge its batteries
 * @param cycles (optional) how many times each philo should eat before we
 * are done
 * @param philos array were all the philos live
 * @param forks array with a mutex per fork
 * @param forks_state array of boolians one per fork, true is they are in
 * use, false if not
 * @param philo_t array with all philo threads
 */
typedef struct s_philos_data
{
	long				*start;
	int					amount;
	long				lifespan;
	long				eat;
	long				sleep;
	int					*cycles;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	bool				*forks_state;
	pthread_t			*philo_t;
}t_philos_data;

/**
 * check for given data and store values if everything is ok
 * @param argc amont of args
 * @param argv array of args
 * @param run philo data struct
 * @return 0 if success 1 if data is invalid 2 if malloc fails
 */
int		set_data(int argc, char **argv, t_philos_data *run);
/**
 * create and initialize array of philos with given information
 * @param philos_data
 * @return
 */
int		create_philos(t_philos_data *philos_data);
/**
 * create one thread per philo and call the monitoring function
 * that will check if everything is ok otherwise joins back to main
 * @param philos_data
 * @return 0 on success or 1 on failure
 */
int		thread_philos(t_philos_data *philos_data);
/**
 * init all needed mutexes and forks
 * @param philos_data
 * @return 0 on success or 1 on failure
 */
int		init_mutexes(t_philos_data *philos_data);
/**
 * destroy all mutexes
 * @param philos_data
 */
void	destroy_mutexes(t_philos_data *philos_data);
/**
 * creare and initialize an array with one mutex per fork as well as
 * a array of boolians containing a mutex pper fork, all initialized
 * as false
 * @param philos_data
 * @return 0 on success or 1 on malloc fail
 */
int		create_forks(t_philos_data *philos_data);
/**
 * Routine that keeps the philos on a pick_forks, eat, sleep untill
 * either one philo is dead or all philos had at least x amount of
 * meals
 * @param philo_data
 * @return NUll when it's done
 */
void	*philo_routine(void *philo_data);
/**
 * Routine in case there is a single philo a the table
 * @param philo
 * @return NUll when it's done
 */
void	*single_philo_routine(void *philo);
/**
 * Free data and destroy mutexes
 * @param philos_data
 */
void	free_data(t_philos_data *philos_data);
//void	lock_forks(t_philo *philo);
/**
 * use forks mutexes to change the forks_state once philos is done eating
 * @param philo
 */
void	unlock_forks(t_philo *philo);
/**
 * destroy writing mutexes and free philos array
 * @param philos_data
 */
void	free_philos(t_philos_data *philos_data);
/**
 * given philo locks first fork, checks if it is available
 * if it is, wait to lock second fork and if it's also available,
 * change theis status unlock mutexes and go eat. If any fork is
 * unavailable mutexes are unclocked and philo sleeps a bit before
 * next attempt
 * @param philo
 * @return
 */
bool	grab_forks(t_philo *philo);
void	set_forks(t_philo *philo);
void	phi_food_message(t_philo *philo, char *message);
void	set_forks_odd_even(t_philo *philo);
#endif //PHILOS_H
