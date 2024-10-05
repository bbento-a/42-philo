// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philos_at_table.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/30 09:43:32 by bbento-a          #+#    #+#             */
// /*   Updated: 2024/10/03 14:20:06 by bbento-a         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "philo.h"

// This is the the function use for the "dining" simulation

void	*at_table(void *phl_dt)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = (t_philo *)phl_dt;
	data = philo->data;
	ft_setting_threads(data);
	// gettimeofday for when simu started
	while(!is_dead(data, philo))
	{
		//eat
		philo_eat(data, philo);
		//sleep
		if (!is_dead(data, philo))	
			philo_sleep(data, philo);
		//think (thinking time is necessary so the simulation is as fair as possible)
		if (!is_dead(data, philo))
			philo_think(data, philo);
	}
	// Do routine
	return ;
}
// Main loop for the program

void	simulation_cycle(t_data *data)
{
	int	i;

	if (data->n_philos == 1)
	{
		// case for only 1 philo
		return ;
	}
	i = 0;
	while(i < data->n_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, &at_table, &data->philos[i]);
		i++;
	}
}