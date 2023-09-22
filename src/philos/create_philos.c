//
// Created by lpraca-l on 9/21/23.
//
#include "../../include/philos.h"
#include "../../include/utils.h"

int	create_philos(t_philos_data *philos_data)
{
	int	count;

	count = 1;
	philos_data->philos = ft_calloc((philos_data->amount + 1), sizeof (t_philo *));
	if (philos_data->philos == NULL)
		return (1);
	while(count <= philos_data->amount)
	{
		philos_data->philos[count - 1]  = ft_calloc(1, sizeof (t_philo));
		if (philos_data->philos[count - 1] == NULL)
			return (1);
		philos_data->philos[count - 1]->number = count;
		count++;
	}
	philos_data->philos[count - 1] = NULL;
	print_philos(philos_data->philos);
	return (0);
	//TODO track fail
}
