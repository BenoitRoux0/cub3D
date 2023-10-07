/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:40:35 by beroux            #+#    #+#             */
/*   Updated: 2023/10/03 15:21:29 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	clear_sprites(t_sprites_list **lst)
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		clear_sprites(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

void	clear_sprites_img(t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (sprite[i].src)
			printf("clearing %c\n", i + 'a');
		if (sprite[i].src)
			clear_img(sprite[i].src);
		i++;
	}
	return;
}
