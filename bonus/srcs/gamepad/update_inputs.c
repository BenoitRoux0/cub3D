/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:44:28 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 07:26:19 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad.h"

#define MAX_EVENTS 0xff

int	update_inputs(t_gamepad *gamepad)
{
	struct js_event	events[MAX_EVENTS];
	size_t			i;
	ssize_t			readed;

	if (gamepad->connected == false)
		return (0);
	i = 0;
	readed = read(gamepad->fd, events, sizeof(struct js_event) * MAX_EVENTS);
	while (i < MAX_EVENTS && i < readed / sizeof(struct js_event) && readed > 0)
	{
		if (events[i].type == JS_EVENT_BUTTON && \
				gamepad->button_hooks[button_pressed] && events[i].value == 1)
			gamepad->button_hooks[button_pressed](events[i].number, \
									gamepad->button_params[button_pressed]);
		else if (events[i].type == JS_EVENT_BUTTON && \
				gamepad->button_hooks[button_released] && events[i].value == 0)
			gamepad->button_hooks[button_released](events[i].number, \
									gamepad->button_params[button_released]);
		else if (events[i].type == JS_EVENT_AXIS && gamepad->axis_hook)
			gamepad->axis_hook(events[i].number, \
										events[i].value, gamepad->axis_param);
		i++;
	}
	return (0);
}
