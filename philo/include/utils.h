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
# include "philos.h"

/**
 * Compares string 1 and 2 for given length
 * @param str1
 * @param str2
 * @param len
 * @return 0 if equals or 1 if different
 */
int		phi_strncmp(const char *str1, const char *str2, int len);
/**
 * Converts string into integer
 * @param str
 * @return number
 */
int		phi_atoi(const char *str);
/**
 * @param str
 * @return length of given string
 */
int		phi_strlen(const char *str);
/**
 * Print error message on stderror
 * @param error
 */
void	phi_error(char *error);
/**
 * malloc memory and fills everything with null
 * @param count
 * @param size
 * @return allocated memory
 */
void	*ft_calloc(size_t count, size_t size);
/**
 * print all philos data
 * @param philos array of philos
 * @param size amount of philos
 */
void	print_philos(t_philo *philos, size_t size);
/**
 * locks given philo writing mutex, checks for dead, if
 * everything is ok, lock message mutex and prints given message
 * @param philo
 * @param message
 */
void	phi_message(t_philo *philo, char *message);
/**
 * @return current time
 */
int		phi_time(void);
/**
 * break usleep into bits for accuracy and to check if everybody is
 * still alive, if anyone dies, usleep is inta-done
 * @param philo
 * @param time
 */
void	phi_usleep(t_philo *philo, long time);
/**
 * message once both forks have been taken
 * @param philo
 * @param message
 */
void	phi_fork_message(t_philo *philo, char *message);
/**
 * Debugging message that prints hhow many times given
 * philo tried to grab forks
 * @param philo
 * @param message
 */
void	phi_attempt_message(t_philo *philo, char *message);
/**
 * Debugging message that prints how many meals given philo had
 * @param philo
 * @param message
 */
void	phi_meals_message(t_philo *philo, char *message);
int		phi_isdigit(int c);
#endif //UTILS_H
