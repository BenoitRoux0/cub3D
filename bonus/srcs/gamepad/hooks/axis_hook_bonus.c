/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:24:00 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 07:24:00 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"

void	axis_hook(t_gamepad *gamepad, t_axis_func func, \
						int js_number, void *data)
{
	int	i;

	i = 0;
	while (i < js_number && gamepad)
		gamepad = gamepad->next;
	if (!gamepad)
		return ;
	gamepad->axis_hook = func;
	gamepad->axis_param = data;
}
