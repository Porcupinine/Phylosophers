/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:37:30 by laura         #+#    #+#                 */
/*   Updated: 2023/10/23 15:05:15 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "philos.h"

/**
 * checks if given data is between min int and max int
 * @param str
 * @return 0 if it is 1 if not
 */
int		check_int_limits(char *str);
/**
 * checks philo by philo everey 9ms, in case of death it activates
 * my_funeral flags or in case that every philo is full activates all_fed
 * @param philos_data
 */
void	check_thread(t_philos_data *philos_data);
/**
 * @param philo
 * @return funeral flag for given philo
 */
bool	check_for_dead(t_philo *philo);
/**
 * checks if given philo is alive, in case of death stes funeral to true
 * and prints dead philo message
 * @param philo
 * @param philos_data
 * @return true if philo is dead or false if philo is alive
 */
bool	dead_or_alive(t_philo *philo, t_philos_data *philos_data);
/**
 * @param philo
 * @return false if philo needs to eat more, true if philo is full
 */
bool	done_meals(t_philo *philo);
/**
 * in case all philos are full it sets all_fed to true
 * @param philos_data
 */
void	all_fed(t_philos_data *philos_data);

#endif //CHECK_H
