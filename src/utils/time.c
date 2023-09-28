/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 14:49:30 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 14:49:30 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

long	phi_time(void)
{
	long			time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}