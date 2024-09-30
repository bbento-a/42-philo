/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:05:59 by bbento-a          #+#    #+#             */
/*   Updated: 2024/09/30 10:18:11 by bbento-a         ###   ########.fr       */
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
	int			n_philos;
	uint64_t	t_die;
	uint64_t	t_eat;
	uint64_t	t_sleep; // For sake of portabily and size, I will be using uint64_t instead of unsigned long
	int			meals;

	t_philo		*philos;
	t_mutex		*forks;
	bool		is_dead;
	bool		ended;
}	t_data;

//
//	FUNCTIONS
//

// parse_args.c
void	parse_args(char **args);

// at_table.c
void	*at_table(void *dt);

// ft_funtions.c
void	exit_phl(char *msg);
long	ft_atol(char *nb);
int	ft_strlen(char *str);

// exit_functions.c
void	p_msg(char *msg);
void	error_func(t_data *data);
void	clear_data(t_data *data);

#endif