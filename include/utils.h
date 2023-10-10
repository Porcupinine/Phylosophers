/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:38:16 by laura         #+#    #+#                 */
/*   Updated: 2023/09/21 16:05:34 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
#include "philos.h"

int		phi_strncmp(const char *str1, const char *str2, int len);
int		phi_atoi(const char *str);
int		phi_strlen(const char *str);
void	phi_error(char *error);
void	*ft_calloc(size_t count, size_t size);
void	print_philos(t_philo *philos, size_t size);
void	phi_message(t_philo *philo, char *message);
int		phi_time(void);
void	phi_usleep(t_philo *philo, long time);
void	phi_fork_message(t_philo *philo, char *message);
void	phi_attempt_message(t_philo *philo, char *message);
void	phi_meals_message(t_philo *philo, char *message);

#endif //UTILS_H
