/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:38:16 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:38:34 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>

int		phi_strncmp(const char *str1, const char *str2, int len);
int		phi_atoi(const char *str);
int		phi_strlen(const char *str);
void	phi_error(char *error);
void	*ft_calloc(size_t count, size_t size);


#endif //UTILS_H
