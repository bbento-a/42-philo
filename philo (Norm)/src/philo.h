/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:05:59 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/16 14:43:32 by bbento-a         ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef enum e_status
{
	E_ALIVE,
	E_DEAD,
}	t_status;

typedef struct s_mutex
{
	int				nb;
	bool			lock;
	pthread_mutex_t	mut;
}	t_mutex;

typedef struct s_philo
{
	int			nb;
	pthread_t	philo;
	uint64_t	t_last_meal;	
	int			meals_nb;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	int				n_philos;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	int				meals;
	t_philo			*philos;
	t_mutex			*forks;
	uint64_t		t_think;
	uint64_t		t_simustart;
	pthread_mutex_t	msg_lock;
	pthread_mutex_t	sync_lock;
	pthread_mutex_t	sync2_lock;
	pthread_mutex_t	death_lock;
	int				ready;
	bool			is_dead;
	bool			ended;
}	t_data;

//
//	FUNCTIONS
//

// philos_init.c
void		data_init(t_data *data, char **args);

// philos_at_table.c
void		*at_table(void *dt);
void		simulation_cycle(t_data *data);

// philos_activity.c
void		philo_eat(t_data *data, t_philo *philo);
void		philo_sleep(t_data *data, t_philo *philo);
void		philo_think(t_data *data, t_philo *philo);
bool		is_dead(t_data *data, t_philo *philo);
void		write_philo_act(t_data *data, t_philo *philo, char *msg);

// philos_forks.c
void		take_forks(t_data *data, t_philo *philo);
void		drop_forks(t_philo *philo);

// ft_funtions.c
long		ft_atol(char *nb);
void		setting_threads(t_data *data);
void		setting_simustart(t_data *data);
uint64_t	define_time(void);
uint64_t	simul_time(t_data *data);

// exit_functions.c
void		exit_phl(char *msg);
void		p_msg(char *msg);
void		error_func(t_data *data);
void		clear_data(t_data *data);

#endif
