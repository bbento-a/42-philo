// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exit_functions.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/25 12:02:18 by bbento-a          #+#    #+#             */
// /*   Updated: 2024/10/01 10:29:54 by bbento-a         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "philo.h"

void	exit_phl(char *msg)
{
	p_msg(msg);
	exit(EXIT_FAILURE);
}

void	p_msg(char *msg)
{
	printf("%s", msg);
}

void	clear_data(t_data *data)
{
	int i;
	
	i = 0;
	if (&data->msg_lock)
		pthread_mutex_destroy(&data->msg_lock);
	if (&data->sync_lock)
		pthread_mutex_destroy(&data->sync_lock);
	if (&data->death_lock)
		pthread_mutex_destroy(&data->death_lock);
	while (i < data->n_philos)
	{
		if(&data->forks[i].mut)
			pthread_mutex_destroy(&data->forks[i].mut);
		i++;
	}
	i = 0;
	while (i++ < data->n_philos)
	{
		if(data->philos[i].philo)
			pthread_detach(data->philos[i].philo);
		i++;
	}
}

void	error_func(t_data *data)
{
	clear_data(data);
	exit_phl("Unexpected error occured\n");
}
