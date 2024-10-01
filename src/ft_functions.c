/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:50:08 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/01 10:47:18 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *nb)
{
	long	res;
	int		i;
	
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = res * 10 + (nb[i] - '0');
		i++;
	}
	return (res);
}
void	ft_setting_threads(t_data *data)
{
	while(!ft_get_mutex_bl(&data->data_lock, data->all_rdy))
		;
}

void	ft_modify_mutex_bl(t_mutex *mutex, bool arg, bool value)
{
	pthread_mutex_unlock(mutex->mut);
	arg = value;
	pthread_mutex_lock(mutex->mut);
}
bool	ft_get_mutex_bl(t_mutex *mutex, bool value)
{
	bool	val;
	
	pthread_mutex_unlock(mutex->mut);
	val = value;
	pthread_mutex_lock(mutex->mut);
	return (val);
}