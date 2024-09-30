/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:43:32 by bbento-a          #+#    #+#             */
/*   Updated: 2024/09/30 15:50:34 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This is the the function use for the "dining" simulation

void	*at_table(void *dt)
{
	dt = (t_data *)dt;
	// t_data *data = (t_data *)dt;
	// Do routine
	printf("test");
	return ((void*) dt);
}
// Main loop for the program

void	simulation_cycle(t_data *data)
{
	// Start up threads (make sure they start at the same time)
	// Eating moment
	// Print message
	// Waiting process (Thinking)
}