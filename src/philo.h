/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:05:59 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/01 11:08:11 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//
//  LIBRARIES, HEADERS AND MACROS
//

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

//
//  STUCTS
//

typedef enum e_status
{
	E_SLEEPING,
	E_EATING,
	E_THINKING,
	E_DEAD,
} t_status;

typedef struct s_mutex
{
	int				nb;
	bool			lock;
	pthread_mutex_t	*mut;
} t_mutex;

typedef struct s_philo
{
	pthread_t	philo;
	int			n_philo;
	uint64_t	t_last_meal;
	
	t_status	status;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
} t_philo;

typedef struct s_data
{
	int				n_philos;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep; // For sake of portabily and size, I will be using uint64_t instead of unsigned long
	int				meals;

	t_philo			*philos;
	t_mutex			*forks;
	t_mutex			data_lock;
	t_mutex			msg_lock;
	bool			all_rdy;
	bool			is_dead;
	bool			ended;
}	t_data;

//
//	FUNCTIONS
//

// philos_init.c
void	philos_init(t_data *data, char **args);

// philos_at_table.c
void	*at_table(void *dt);
void	simulation_cycle(t_data *data);

// philos_activity.c
// void	philo_eat(t_data *data);
// void	philo_sleep(t_data *data);
// void	philo_think(t_data *data);
// void	write_philo_act(t_data *data);

// ft_funtions.c
void	exit_phl(char *msg);
long	ft_atol(char *nb);
void	ft_modify_mutex_bl(t_mutex *mutex, bool arg, bool value);
bool	ft_get_mutex_bl(t_mutex *mutex, bool value);

// exit_functions.c
void	p_msg(char *msg);
void	error_func(t_data *data);
void	clear_data(t_data *data);

#endif