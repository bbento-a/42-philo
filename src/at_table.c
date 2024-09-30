/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:43:32 by bbento-a          #+#    #+#             */
/*   Updated: 2024/09/30 10:26:26 by bbento-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*at_table(void *dt)
{
	dt = (t_data *)dt;
	// t_data *data = (t_data *)dt;
	// Do routine
	printf("test");
	return ((void*) dt);
}