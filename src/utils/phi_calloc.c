/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phi_calloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:47:29 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/09/21 16:04:25 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*alias;

	count = 0;
	alias = (char *) s;
	while (count < n)
	{
		alias[count] = '\0';
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*call;

	call = malloc(count * size);
	if (call == NULL)
		return (NULL);
	ft_bzero(call, (count * size));
	return (call);
}
