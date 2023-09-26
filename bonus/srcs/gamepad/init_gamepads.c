/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gamepads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:50:48 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 03:59:26 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad.h"

static int	add_gamepad(t_gamepad **list);

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
