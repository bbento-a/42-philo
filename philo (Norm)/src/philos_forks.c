/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:31:39 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/16 14:57:44 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_data *data, t_philo *philo)
{
	while (!is_dead(data, philo))
	{
		pthread_mutex_lock(&philo->l_fork->mut);
		if (philo->l_fork->lock == false)
		{
			philo->l_fork->lock = true;
			pthread_mutex_unlock(&philo->l_fork->mut);
			write_philo_act(data, philo, "has taken a fork");
			break ;
		}
		pthread_mutex_unlock(&philo->l_fork->mut);
	}
	while (!is_dead(data, philo))
	{
		pthread_mutex_lock(&philo->r_fork->mut);
		if (philo->r_fork->lock == false)
		{
			philo->r_fork->lock = true;
			pthread_mutex_unlock(&philo->r_fork->mut);
			write_philo_act(data, philo, "has taken a fork");
			break ;
		}
		pthread_mutex_unlock(&philo->r_fork->mut);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mut);
	philo->l_fork->lock = false;
	pthread_mutex_unlock(&philo->l_fork->mut);
	pthread_mutex_lock(&philo->r_fork->mut);
	philo->r_fork->lock = false;
	pthread_mutex_unlock(&philo->r_fork->mut);
}
