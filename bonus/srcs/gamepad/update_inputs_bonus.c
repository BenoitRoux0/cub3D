/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:44:28 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:06:34 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"

static void	register_input(t_gamepad *gamepad, struct js_event event);

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
		register_input(gamepad, events[i]);
		i++;
	}
	return (0);
}

static void	register_input(t_gamepad *gamepad, struct js_event event)
{
	int i;

	i = 0;
	pthread_mutex_lock(gamepad->states[i].mutex);
	while (i < MAX_EVENTS && gamepad->states[i].updated)
	{
		pthread_mutex_unlock(gamepad->states[i].mutex);
		i++;
		if (i < MAX_EVENTS)
			pthread_mutex_lock(gamepad->states[i].mutex);
	}
	if (i < MAX_EVENTS)
	{
		gamepad->states[i].updated = true;
		gamepad->states[i].event = event;
		pthread_mutex_unlock(gamepad->states[i].mutex);
	}
}
