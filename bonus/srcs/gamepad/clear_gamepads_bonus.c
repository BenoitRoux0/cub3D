/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_gamepads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:31:29 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:31:14 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"

static void	clear_mutexes(t_gamepad *gamepad);

void	clear_gamepads(t_gamepad **list)
{
	if (!list || !*list)
		return ;
	pthread_mutex_lock((*list)->mutex);
	(*list)->end = 1;
	pthread_mutex_unlock((*list)->mutex);
	if ((*list)->thread)
		pthread_join((*list)->thread, NULL);
	if ((*list)->next)
		clear_gamepads(&(*list)->next);
	if ((*list)->name)
	{
		free((*list)->name);
		(*list)->name = NULL;
	}
	if ((*list)->fd != -1)
	{
		close((*list)->fd);
		(*list)->fd = -1;
	}
	clear_mutexes(*list);
	free(*list);
	*list = NULL;
}

static void	clear_mutexes(t_gamepad *gamepad)
{
	int i;

	i = 0;
	pthread_mutex_destroy(gamepad->mutex);
	free(gamepad->mutex);
	gamepad->mutex = NULL;
	while (i < MAX_EVENTS)
	{
		if (gamepad->states[i].mutex)
		{
			pthread_mutex_destroy(gamepad->states[i].mutex);
			free(gamepad->states[i].mutex);
			gamepad->states[i].mutex = NULL;
		}
		i++;
	}
}