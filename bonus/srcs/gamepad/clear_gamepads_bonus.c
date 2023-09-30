/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_gamepads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:31:29 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 16:03:30 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad_bonus.h"

void	clear_gamepads(t_gamepad **list)
{
	if (!list || !*list)
		return ;
	if ((*list)->next)
		clear_gamepads(&(*list)->next);
	if ((*list)->name)
		free((*list)->name);
	if ((*list)->fd != -1)
		close((*list)->fd);
	free(*list);
	*list = NULL;
}
