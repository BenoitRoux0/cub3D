/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:52:06 by beroux            #+#    #+#             */
/*   Updated: 2023/10/05 06:14:57 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static t_sprites_list	*new_node(int pos[2], t_sprite *sprite, \
									double player_pos[2]);

void	hit_sprite(t_data *data, t_sprites_list **lst, \
					int pos[2], char type)
{
	t_sprites_list	*tmp;
	t_sprites_list	*new;

	new = new_node(pos, data->map.sprites + (type - 'a'), data->player.pos);
	if (!new)
		return ;
	tmp = *lst;
	while (tmp && tmp->next && tmp->next->square_dist >= new->square_dist)
	{
		if ((tmp->pos[0] == pos[0] && tmp->pos[1] == pos[1]) || \
			(tmp->next->pos[0] == pos[0] && tmp->next->pos[1] == pos[1]))
		{
			free(new);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp)
	{
		new->next = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

static t_sprites_list	*new_node(int pos[2], t_sprite *sprite, \
									double player_pos[2])
{
	t_sprites_list	*node;
	int				true_pos[2];

	node = malloc(sizeof (t_sprites_list));
	if (!node)
		return (NULL);
	true_pos[0] = pos[0] * CELL_SIZE + sprite->x_pos * CELL_SIZE;
	true_pos[1] = pos[1] * CELL_SIZE + sprite->y_pos * CELL_SIZE;
	ft_bzero(node, sizeof (t_sprites_list));
	node->pos[0] = pos[0];
	node->pos[1] = pos[1];
	node->sprite = sprite;
	node->square_dist = pow(player_pos[0] - true_pos[0], 2) + \
						pow(player_pos[1] - true_pos[1], 2);
	return (node);
}
