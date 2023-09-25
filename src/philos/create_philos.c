/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_philos.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/25 14:35:45 by laura         #+#    #+#                 */
/*   Updated: 2023/09/25 14:35:45 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philos.h"
#include "../../include/utils.h"

int	create_philos(t_philos_data *philos_data)
{
	int	count;

	count = 1;
	philos_data->philos = ft_calloc((philos_data->amount + 1), \
	sizeof (t_philo));
	if (philos_data->philos == NULL)
		return (1);
	while (count <= philos_data->amount)
	{
		philos_data->philos[count - 1].number = count;
		count++;
	}
	print_philos(philos_data->philos, philos_data->amount);
	return (0);
	//TODO track fail
}
