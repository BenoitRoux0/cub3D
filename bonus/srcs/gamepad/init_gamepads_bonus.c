/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gamepads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:50:48 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:27:32 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"
#include <stdio.h>

static int	add_gamepad(t_gamepad **list);
static int	init_mutexes(t_gamepad *gamepad);

t_gamepad	*init_gamepads(int nb_gamepads)
{
	int			i;
	t_gamepad	*list;

	i = 0;
	list = NULL;
	while (i < nb_gamepads)
	{
		if (add_gamepad(&list))
			return (clear_gamepads(&list), NULL);
		++i;
	}
	pthread_create(&list->thread, NULL, (void *(*)(void *)) input_loop, list);
	return (list);
}

static int	add_gamepad(t_gamepad **list)
{
	t_gamepad	*tmp;
	t_gamepad	*new;

	if (!list)
		return (-1);
	new = malloc(sizeof(t_gamepad));
	if (!new)
		return (-1);
	bzero(new, sizeof(t_gamepad));
	if (init_mutexes(new))
		return (free(new), -1);
	new->fd = -1;
	if (!*list)
	{
		*list = new;
		return (0);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

static int	init_mutexes(t_gamepad *gamepad)
{
	int	i;

	i = 0;
	gamepad->mutex = malloc(sizeof (pthread_mutex_t));
	pthread_mutex_init(gamepad->mutex, NULL);
	while (i < MAX_EVENTS)
	{
		gamepad->states[i].mutex = malloc(sizeof (pthread_mutex_t));
		if (!gamepad->states[i].mutex)
			return (-1);
		if (pthread_mutex_init(gamepad->states[i].mutex, NULL))
			return (free(gamepad->states[i].mutex), -1);
		i++;
	}
	return (0);
}
