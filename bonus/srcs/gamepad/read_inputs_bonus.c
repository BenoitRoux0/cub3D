/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:40:17 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:33:06 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	call_funcs(t_gamepad *gamepad, int event_pos);

int	read_inputs(t_gamepad *gamepad)
{
	int	i;

	pthread_mutex_lock(gamepad->mutex);
	if (gamepad->connected == false)
		return (pthread_mutex_unlock(gamepad->mutex), 0);
	i = 0;
	pthread_mutex_lock(gamepad->states[i].mutex);
	while (i < MAX_EVENTS)
	{
		if (gamepad->states[i].updated)
			call_funcs(gamepad, i);
		pthread_mutex_unlock(gamepad->states[i].mutex);
		i++;
		if (i < MAX_EVENTS)
			pthread_mutex_lock(gamepad->states[i].mutex);
	}
	return (pthread_mutex_unlock(gamepad->mutex), 0);
}

static void	call_funcs(t_gamepad *gamepad, int event_pos)
{
	if (gamepad->states[event_pos].event.type == JS_EVENT_BUTTON && \
		gamepad->button_hooks[button_pressed] && \
		gamepad->states[event_pos].event.value == 1)
		gamepad->button_hooks[button_pressed](\
					gamepad->states[event_pos].event.number, \
					gamepad->button_params[button_pressed]);
	else if (gamepad->states[event_pos].event.type == JS_EVENT_BUTTON && \
			gamepad->button_hooks[button_released] && \
			gamepad->states[event_pos].event.value == 0)
		gamepad->button_hooks[button_released](\
				gamepad->states[event_pos].event.number, \
				gamepad->button_params[button_released]);
	else if (gamepad->states[event_pos].event.type == JS_EVENT_AXIS && \
			gamepad->axis_hook)
		gamepad->axis_hook(\
					gamepad->states[event_pos].event.number, \
					gamepad->states[event_pos].event.value, \
					gamepad->axis_param);
	gamepad->states[event_pos].updated = false;
}
