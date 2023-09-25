/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:24:06 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 07:24:06 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad.h"

void	button_pressed_hook(t_gamepad *gamepad, t_button_func func, \
									int js_number, void *data)
{
	int	i;

	i = 0;
	while (i < js_number && gamepad)
		gamepad = gamepad->next;
	if (!gamepad)
		return ;
	gamepad->button_hooks[button_pressed] = func;
	gamepad->button_params[button_pressed] = data;
}

void	button_released_hook(t_gamepad *gamepad, t_button_func func, \
									int js_number, void *data)
{
	int	i;

	i = 0;
	while (i < js_number && gamepad)
		gamepad = gamepad->next;
	if (!gamepad)
		return ;
	gamepad->button_hooks[button_released] = func;
	gamepad->button_params[button_released] = data;
}
