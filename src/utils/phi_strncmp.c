/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phi_strncmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 10:33:47 by laura         #+#    #+#                 */
/*   Updated: 2023/09/18 10:33:59 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	phi_strncmp(const char *str1, const char *str2, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (str1[count] != str2[count])
			return (1);
		count++;
	}
	return (0);
}
