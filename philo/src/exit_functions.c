/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:02:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/16 15:17:57 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	pthread_mutex_destroy(&data->msg_lock);
	pthread_mutex_destroy(&data->sync_lock);
	pthread_mutex_destroy(&data->sync2_lock);
	pthread_mutex_destroy(&data->death_lock);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i].mut);
		i++;
	}
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

void	error_func(t_data *data)
{
	clear_data(data);
	exit_phl("Unexpected error occured\n");
}
