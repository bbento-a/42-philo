/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 08:31:39 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/15 19:19:26 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Takes a philo that will try to take a fork, if it is avaiable

void	take_forks(t_data *data, t_philo *philo)
{
	while (!is_dead(data, philo))
	{
		pthread_mutex_lock(&philo->l_fork->mut);
		if (philo->l_fork->lock == false)  // If the fork is not taken, then philo will take it
		{
			philo->l_fork->lock = true;
			pthread_mutex_unlock(&philo->l_fork->mut);
			write_philo_act(data, philo, "has taken a fork");
			break ;
		}
		pthread_mutex_unlock(&philo->l_fork->mut); // if not, it will just unlock the mutex for other philos check as well
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
// Takes a philo after eating and drops his forks

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mut);
	philo->l_fork->lock = false;
	pthread_mutex_unlock(&philo->l_fork->mut);
	pthread_mutex_lock(&philo->r_fork->mut);
	philo->r_fork->lock = false;
	pthread_mutex_unlock(&philo->r_fork->mut);
}

