/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:04:46 by bbento-a          #+#    #+#             */
/*   Updated: 2024/10/16 13:07:22 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if the input has valid characters (aka only digits)

void	parse_args(char **args)
{
	int	i;
	int j;
	
	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] >= '0' && args[i][j] <= '9')
				j++;
			else
				exit_phl("Arguments can only be digits\n");
		}
		i++;
	}
}
// Main function

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		p_msg("Invalid arguments.\nTry <nº_philos>, time to <die>, <eat>,");
		p_msg(" <sleep>, <nº_of_reps> (meals)\n");
		return (1);
	}
	parse_args(argv);
	data_init(&data, argv);
	if (data.meals != 0)
		simulation_cycle(&data);
	clear_data(&data);
	return (0);
}
