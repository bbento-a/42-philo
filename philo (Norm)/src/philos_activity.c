/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_activity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:58:40 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/17 15:02:16 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_data *data, t_philo *philo)
{
	uint64_t	elapsed;
	uint64_t	bgn;
	
	elapsed = 0;
	take_forks(data, philo);
	if (!is_dead(data, philo))
		write_philo_act(data, philo, "is eating");
	philo->t_last_meal = simul_time(data);
	bgn = simul_time(data);
	while (!is_dead(data, philo) && elapsed <= data->t_eat)
	{
		usleep(100);
		elapsed = simul_time(data) - bgn;
	}
	drop_forks(philo);
	philo->meals_nb++;
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	uint64_t	asleep;
	uint64_t	bgn;

	asleep = 0;
	bgn = simul_time(data);
	write_philo_act(data, philo, "is sleeping");
	while (!is_dead(data, philo) && asleep <= data->t_sleep)
	{
		usleep(100);
		asleep = simul_time(data) - bgn;
	}
}

void	philo_think(t_data *data, t_philo *philo)
{
	uint64_t	think_elps;
	uint64_t	bgn;

	think_elps = 0;
	bgn = simul_time(data);
	write_philo_act(data, philo, "is thinking");
	while (!is_dead(data, philo) && think_elps <= data->t_think)
	{
		usleep(100);
		think_elps = simul_time(data) - bgn;
	}
}

bool	is_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_lock);
	if (data->is_dead == E_DEAD)
	{
		pthread_mutex_unlock(&data->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&data->death_lock);
	if (simul_time(data) - philo->t_last_meal >= data->t_die)
	{
		pthread_mutex_lock(&data->death_lock);
		data->is_dead = E_DEAD;
		pthread_mutex_unlock(&data->death_lock);
		write_philo_act(data, philo, "died");
		return (true);
	}
	return (false);
}

void	write_philo_act(t_data *data, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data->msg_lock);
	printf("%ld %d %s\n", simul_time(data), philo->nb, msg);
	pthread_mutex_unlock(&data->msg_lock);
}
