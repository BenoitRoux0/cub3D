/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:08:09 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 07:26:54 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad.h"

int	input_loop(t_gamepad *gamepad)
{
	t_gamepad	*tmp;

	while (1)
	{
		update_gamepads(gamepad);
		tmp = gamepad;
		while (tmp)
		{
			update_inputs(tmp);
			tmp = tmp->next;
		}
		usleep(10000);
	}
	return (0);
}
