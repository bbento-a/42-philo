/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_at_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:43:32 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/16 14:55:55 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*at_table(void *phl_dt)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)phl_dt;
	data = philo->data;
	if (philo->nb % 2 == 0)
		usleep(10000);
	setting_simustart(data);
	while (!is_dead(data, philo))
	{
		philo_eat(data, philo);
		if (philo->meals_nb == data->meals && data->meals != -1)
			break ;
		if (!is_dead(data, philo))
			philo_sleep(data, philo);
		else
			return ((void *) phl_dt);
		if (!is_dead(data, philo))
			philo_think(data, philo);
		else
			return ((void *) phl_dt);
	}
	return ((void *) phl_dt);
}

void	simulation_cycle(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, &at_table, \
				&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
}
