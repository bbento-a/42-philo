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
	data->t_simustart = define_time();
	while(!is_dead(data, philo))
	{
		//eat
		philo_eat(data, philo);
		if (philo->meals_nb == data->meals && data->meals != -1) // is philo full?
			break ;
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

// Function to handle 1 philo at the simulation (it has to die since it doesn't have a 2nd fork)

void	*alone_at_table(void *phl_dt)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = (t_philo *)phl_dt;
	data = philo->data;
	ft_setting_threads(data);
	data->t_simustart = define_time();
	while (!is_dead(data, philo))
	{
		usleep(100);
	}
}


// Main loop for the program

void	simulation_cycle(t_data *data)
{
	int	i;

	if (data->n_philos == 1)
	{
		// case for only 1 philo
		pthread_create(&data->philos[0].philo, NULL, &alone_at_table, &data->philos[0]);
		return ;
	}
	i = 0;
	while(i < data->n_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, &at_table, &data->philos[i]);
		i++;
	}
}