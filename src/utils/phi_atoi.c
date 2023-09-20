/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phi_atoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:34:33 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:34:49 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/check.h"

static int	phi_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	phi_atoi(const char *str)
{
	int		count;
	int		nbr;

	count = 0;
	nbr = 0;
	while (phi_isdigit(str[count]) != 0)
	{
		nbr = ((nbr * 10) + (str[count] - 48));
		count++;
	}
	return (nbr);
}
