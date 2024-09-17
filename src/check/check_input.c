/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:37:00 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:37:16 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

static int	check_max_int(char *str)
{
	if (str[0] == '-')
		return (0);
	if (phi_strlen(str) > 10)
		return (1);
	if (phi_strlen(str) == 10)
		if (phi_strncmp(str, "2147483647", 10) > 0)
			return (1);
	return (0);
}

static int	check_min_int(char *str)
{
	if (phi_strlen(str) > 11)
		return (1);
	if (phi_strlen(str) == 11)
		if (phi_strncmp(str, "-2147483648", 11) > 0)
			return (1);
	return (0);
}

int	check_int_limits(char *str)
{
	if (check_max_int(str) == 0 && check_min_int(str) == 0)
		return (0);
	return (1);
}
