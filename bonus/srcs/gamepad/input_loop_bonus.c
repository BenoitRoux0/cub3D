/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:08:09 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:29:32 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"
#include <stdio.h>

void	*input_loop(t_gamepad *gamepad)
{
	t_gamepad	*tmp;

	pthread_mutex_lock(gamepad->mutex);
	while (!gamepad->end)
	{
		pthread_mutex_unlock(gamepad->mutex);
		update_gamepads(gamepad);
		tmp = gamepad;
		while (tmp)
		{
			update_inputs(tmp);
			tmp = tmp->next;
		}
		pthread_mutex_lock(gamepad->mutex);
	}
	pthread_mutex_unlock(gamepad->mutex);
	return (NULL);
}
