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

static int	deal_isspace_issign(char *a, int *count, int *count_m, int *count_p)
{
	while (a[*count] == ' ' || a[*count] == '\t' \
	|| a[*count] == '\r' || a[*count] == '\n' \
	|| a[*count] == '\v' || a[*count] == '\f')
		(*count)++;
	while (a[*count] == '-')
	{
		if (a[*count + 1] == '+' || a[*count + 1] == '-')
			return (0);
		(*count)++;
		(*count_m)++;
	}
	if (a[*count] == '+')
	{
		if (a[*count + 1] == '+')
			return (0);
		(*count)++;
		(*count_p)++;
	}
	return (1);
}

int	phi_atoi(const char *nptr)
{
	int		count;
	char	*alias;
	int		nbr;
	int		count_m;
	int		count_p;

	alias = (char *) nptr;
	count = 0;
	count_m = 0;
	nbr = 0;
	count_p = 0;
	if (deal_isspace_issign(alias, &count, &count_m, &count_p) == 0)
		return (0);
	while (phi_isdigit(alias[count]) != 0)
	{
		nbr = ((nbr * 10) + (alias[count] - 48));
		count++;
	}
	if (count_m == 1)
	{
		nbr = (-1 * nbr);
		return (nbr);
	}
	return (nbr);
}
