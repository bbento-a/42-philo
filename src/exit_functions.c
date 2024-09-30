/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:02:18 by bbento-a          #+#    #+#             */
/*   Updated: 2024/09/30 10:22:12 by bbento-a         ###   ########.fr       */
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

void	error_func(t_data *data)
{
	data = (void*)data;
	// clear data
	// exit
}

void	clear_philos(t_data *data)
{
	data = (void*)data;
	// int	i;

	// i = 0;
	// while (data->philos[i])
}

void	clear_data(t_data *data)
{
	if (data->philos)
		clear_philos(data);
}