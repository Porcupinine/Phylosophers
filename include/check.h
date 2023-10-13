/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:37:30 by laura         #+#    #+#                 */
/*   Updated: 2023/09/21 16:05:29 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

#include "philos.h"

int	check_int_limits(char *str);
void	check_thread(t_philos_data *philos_data);
bool	check_for_dead(t_philo *philo);
bool	dead_or_alive(t_philo *philo, t_philos_data *philos_data);
bool	done_meals(t_philo *philo);
void	all_fed(t_philos_data *philos_data);


#endif //CHECK_H
