/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:00:38 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/01 11:03:31 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initiates and allocates all forks and other mutexs

void	mutex_alloc(t_data *data)
{
	int	i;

	if (!pthread_mutex_init(data->data_lock.mut, NULL))
		error_func(data);
	data->data_lock.lock = false;
	data->data_lock.nb = -1;
	if (!pthread_mutex_init(data->msg_lock.mut, NULL))
		error_func(data);
	data->msg_lock.lock = false;
	data->msg_lock.nb = -1;
	i = -1;
	while (i++ < data->n_philos)
	{
		if (!pthread_mutex_init(data->forks[i].mut, NULL))
			error_func(data);
		data->forks[i].nb = i;
		data->forks[i].lock = false;
	}
}

// Initiates and allocates all philos (threads)

void	philos_alloc(t_data *data)
{
	int	i;
	int	l_nb;

	i = -1;
	while (i++ < data->n_philos)
	{
		data->philos[i].n_philo = i;
		data->philos[i].status = -1;
		data->philos[i].r_fork = &data->forks[i];
		l_nb = (i + 1) % data->n_philos;
		data->philos[i].l_fork = &data->forks[l_nb];
		data->philos[i].t_last_meal = 0;
	}
}
// Initiates all values from data

void	philos_init(t_data *data, char **args)
{
	data->n_philos = (int)ft_atol(args[1]);
	data->t_die = (uint64_t)ft_atol(args[2]);
	data->t_eat = (uint64_t)ft_atol(args[3]);
	data->t_sleep = (uint64_t)ft_atol(args[4]);
	if (args[5])
		data->meals = (int)ft_atol(args[5]);
	else
		(*data).meals = -1;
	if (data->n_philos == 0)
		exit_phl("Invalid number of philos");
	if (data->t_die > LONG_MAX || data->t_eat > LONG_MAX
		|| data->t_sleep > LONG_MAX || data->n_philos > INT_MAX
		|| data->meals > INT_MAX)
		exit_phl("Arguments values are too big");
	data->all_rdy = false;
	data->is_dead = false;
	data->ended = false;
	data->philos = malloc(sizeof(t_philo) * data->n_philos);
	data->forks = malloc(sizeof(t_mutex) * data->n_philos);
	if (!data->forks || !data->philos)
		return ;
	mutex_alloc(data);
	philos_alloc(data);
}