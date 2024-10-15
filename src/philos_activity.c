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
	write_philo_act(data, philo, "is eating");
	if (!is_dead(data, philo))
		usleep(data->t_eat * 1000);
	// printf ("%d will drop forks\n", philo->nb);
	drop_forks(philo);
	philo->t_last_meal = simul_time(data);
	philo->meals_nb++;
}
// Time philo takes to sleep (4th arg)

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
// This is needed for fairness reasons. This prevents philos from eating 
// right after they wake up. This is very important in case there is an odd number
// of philos.
// Thinking time exists when eating time is more than sleeping time.
// So thinking time should be t_eat - t_sleep

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
	usleep(data->t_eat);
}

// Checks if is there a philo dead during simulation

bool	is_dead(t_data *data, t_philo *philo)
{
	if (philo->status == E_ALIVE)
	{
		pthread_mutex_lock(&data->death_lock);
		if (data->is_dead == E_DEAD)
			return (true);
		pthread_mutex_unlock(&data->death_lock);
	}
	if (simul_time(data) - philo->t_last_meal >= data->t_die)
	{
		pthread_mutex_lock(&data->death_lock);
		data->is_dead = E_DEAD;
		pthread_mutex_unlock(&data->death_lock);
		philo->status = E_DEAD;
		write_philo_act(data, philo, "has died");
		return (true);
	}
	return (false);
}



// Checks if is there a philo dead during simulation

// bool	is_dead(t_data *data, t_philo *philo)
// {
// 	if (philo->status == E_DEAD)
// 		return (true);
// 	if (simul_time(data) - philo->t_last_meal >= data->t_die)
// 	{
// 		philo->status = E_DEAD;
// 		write_philo_act(data, philo, "has died");
// 		return (true);
// 	}
// 	return (false);
// }
// Displays a message of the philo's activity

void	write_philo_act(t_data *data, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data->msg_lock);
	// printf("%ld --- Philo %d %s\n", simul_time(data), philo->nb, msg);
	printf("%ld %d %s\n", simul_time(data), philo->nb, msg);
	pthread_mutex_unlock(&data->msg_lock);
}


// backup func

// void	philo_eat(t_data *data, t_philo *philo)
// {
// 	uint64_t	eat_elps;
// 	uint64_t	bgn;

// 	eat_elps = 0;
// 	bgn = simul_time(data);
// 	take_forks(data, philo);
// 	write_philo_act(data, philo, "is eating");
// 	if (!is_dead(data, philo) && eat_elps <= data->t_eat)
// 	{
// 		usleep(100);
// 		eat_elps = simul_time(data) - bgn;
// 	}
// 	drop_forks(philo);
// 	philo->t_last_meal = simul_time(data);
// 	philo->meals_nb++;
// }