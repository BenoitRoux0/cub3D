/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:16:19 by beroux            #+#    #+#             */
/*   Updated: 2023/10/03 14:56:27 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_BONUS_H
# define SPRITES_BONUS_H

# include "cub_bonus.h"

void	hit_sprite(t_data *data, t_sprites_list **lst, \
					int pos[2], char type);
void	clear_sprites(t_sprites_list **lst);
void	fill_sprites_buffers(t_data *data);
void	draw_sprites(t_data *data);
void	clear_sprites_img(t_sprite *sprite);

#endif
