// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philos_init.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/07 16:00:38 by bbento-a          #+#    #+#             */
// /*   Updated: 2024/10/03 12:37:17 by bbento-a         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "philo.h"

// Defines thinking time for various cases

void	define_t_tthink(t_data *data)
{
	if ((data->n_philos % 2 == 0 && data->t_eat <= data->t_sleep)
		|| data->n_philos <= 1)
		data->t_think = 0;
	else if (data->n_philos % 2 == 0 && data->t_eat > data->t_sleep)
		data->t_think = data->t_eat - data->t_sleep;
	else if (data->n_philos % 2 != 0)
		data->t_think = data->t_eat * 2 - data->t_sleep;
}

// Initiates and allocates all forks and other mutexs

void	mutex_alloc(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->msg_lock, NULL))
		error_func(data);
	if (pthread_mutex_init(&data->sync_lock, NULL))
		error_func(data);
	if (pthread_mutex_init(&data->death_lock, NULL))
		error_func(data);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i].mut, NULL))
			error_func(data);
		data->forks[i].nb = i;
		data->forks[i].lock = false;
		i++;
	}
}
// Initiates and allocates all philos (threads)

void	philos_alloc(t_data *data)
{
	int	i;
	int	l_nb;

	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].nb = i;
		data->philos[i].status = E_ALIVE;
		if (data->meals != -1)
			data->philos[i].meals_nb = 0;
		else
			data->philos[i].meals_nb = -1;
		data->philos[i].r_fork = &data->forks[i];
		l_nb = (i + 1) % data->n_philos;
		data->philos[i].l_fork = &data->forks[l_nb];
		data->philos[i].t_last_meal = 0;
		data->philos[i].data = data;
		i++;
	}
}
// Initiates all values from data

void	data_init(t_data *data, char **args)
{
	data->n_philos = (int)ft_atol(args[1]);
	data->t_die = (uint64_t)ft_atol(args[2]);
	data->t_eat = (uint64_t)ft_atol(args[3]);
	data->t_sleep = (uint64_t)ft_atol(args[4]);
	if (args[5])
		data->meals = (int)ft_atol(args[5]);
	else
		data->meals = -1;
	if (data->n_philos == 0)
		exit_phl("Invalid number of philos");
	if (data->t_die > LONG_MAX || data->t_eat > LONG_MAX
		|| data->t_sleep > LONG_MAX || data->n_philos > INT_MAX
		|| data->meals > INT_MAX)
		exit_phl("Arguments values are too big");
	define_t_tthink(data);
	data->ready = 0;
	data->is_dead = false;
	data->ended = false;
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	if (!data->forks || !data->philos)
		return ;
	mutex_alloc(data);
	philos_alloc(data);
}
