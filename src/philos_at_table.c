/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_at_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:43:32 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/01 11:04:06 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This is the the function use for the "dining" simulation

void	*at_table(void *dt)
{
	t_data *data;
	
	data = (t_data *)dt;
	ft_setting_threads();
	while(/*philos havent died*/)
	{
		//eat
		//sleep
		//think (thinking time is necessary so the simulation is as fair as possible)
	}
	// Do routine
	return ((void*) dt);
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
	i = -1;
	while(i++ < data->n_philos)
	{
		pthread_create(&data->philos[i].philo, NULL, &at_table, &data);
	}
	ft_modify_mutex_bl(&data->data_lock, data->all_rdy, true)
}