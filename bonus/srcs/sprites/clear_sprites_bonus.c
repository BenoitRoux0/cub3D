/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:40:35 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 01:56:27 by beroux           ###   ########.fr       */
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
