/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:35:02 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:35:05 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include <unistd.h>

void	phi_error(char *error)
{
	int	len;

	len = phi_strlen(error);
	if (write(2, error, len) == -1)
		return ;
}
