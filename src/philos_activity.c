// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philos_activity.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/01 10:58:40 by bbento-a          #+#    #+#             */
// /*   Updated: 2024/10/03 14:30:47 by bbento-a         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "philo.h"

// Basically all philos activities will be here

// Time philo is locking both forks used to eat (3rd arg)

void	philo_eat(t_data *data, t_philo *philo)
{
	take_forks(data, philo);
	if (!is_dead(data, philo))
	usleep(data->t_eat * 1000);
	drop_forks(data, philo);
	write_philo_act(data, philo, "is eating");
}
// Time philo takes to sleep (4th arg)

void	philo_sleep(t_data *data, t_philo *philo)
{
	usleep(data->t_sleep * 1000);
	write_philo_act(data, philo, "is sleeping");
}
// This is needed for fairness reasons. This prevents philos from eating 
// right after they wake up. This is very important in case there is an odd number
// of philos.
// Thinking time exists when eating time is more than sleeping time.
// So thinking time should be t_eat - t_sleep

void	philo_think(t_data *data, t_philo *philo)
{
	usleep(data->t_eat);
	write_philo_act(data, philo, "is thinking");
}
// Checks if is there a philo dead during simulation

bool	is_dead(t_data *data, t_philo *philo)
{
	if (philo->status == E_DEAD)
		return (true);
	if (simul_time(data) - philo->t_last_meal >= data->t_die)
	{
		philo->status = E_DEAD;
		write_philo_act(data, philo, "has died");
		return (true);
	}
	return (false);
}
// Displays a message of the philo's activity

void	write_philo_act(t_data *data, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data->msg_lock);
	printf("%lld --- Philo %d %s\n", simul_time(data), philo->nb, msg);
	pthread_mutex_unlock(&data->msg_lock);
}