/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:50:08 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/14 21:49:54 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *nb)
{
	long	res;
	int		i;
	
	i = 0;
	res = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10 + (nb[i] - '0');
		i++;
	}
	return (res);
}
void	ft_setting_threads(t_data *data)
{
	pthread_mutex_lock(&data->sync_lock);
	data->ready++;
	// printf("%d\n", data->ready); // For debug
	pthread_mutex_unlock(&data->sync_lock);
	while (data->ready != data->n_philos)
	{
		pthread_mutex_lock(&data->sync_lock);
		if (data->ready != data->n_philos)
		{
			pthread_mutex_unlock(&data->sync_lock);
			break;
		}
		pthread_mutex_unlock(&data->sync_lock);
		usleep(100);
	}
}
// Conversion of gettimeofday() units to return in milliseconds

uint64_t	define_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
// Returns the time elapsed from the simulation

uint64_t	simul_time(t_data *data)
{
	return(define_time() - data->t_simustart);
}