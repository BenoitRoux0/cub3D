/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:52:06 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 01:52:28 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	hit_sprite(t_sprites_list **lst, t_sprite sprites[26], \
					int pos[2], char type)
{
	t_sprites_list	*tmp;

	if (!sprites[type - 'a'].src || !lst || pos[0] < 0 || pos[1] < 0)
		return ;
	if (!(*lst))
	{
		*lst = malloc(sizeof(t_sprites_list));
		if (!(*lst))
			return ;
		(*lst)->pos[0] = pos[0];
		(*lst)->pos[1] = pos[1];
		(*lst)->sprite = sprites + (type - 'a');
		(*lst)->next = NULL;
	}
	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->pos[0] == pos[0] && tmp->pos[1] == pos[1])
			return ;
		tmp = tmp->next;
	}
	tmp->next = malloc(sizeof(t_sprites_list));
	if (!tmp->next)
		return ;
	tmp->next->pos[0] = pos[0];
	tmp->next->pos[1] = pos[1];
	tmp->next->sprite = sprites + (type - 'a');
	tmp->next->next = NULL;
}
