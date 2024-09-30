/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:00:38 by bbento-a          #+#    #+#             */
/*   Updated: 2024/09/30 10:18:38 by bbento-a         ###   ########.fr       */
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
			if (args[i][j] > '0' && args[i][j] < '9')
				j++;
			else
				exit_phl("Arguments can only be positive numbers\n");
		}
		i++;
	}
}
