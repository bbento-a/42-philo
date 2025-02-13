/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:50:08 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/18 10:13:33 by bbento-a         ###   ########.fr       */
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

void	setting_simustart(t_data *data)
{
	pthread_mutex_lock(&data->sync_lock);
	if (data->t_simustart == 0)
		data->t_simustart = define_time();
	pthread_mutex_unlock(&data->sync_lock);
}

uint64_t	define_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t	simul_time(t_data *data)
{
	return (define_time() - data->t_simustart);
}
