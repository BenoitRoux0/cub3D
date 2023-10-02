/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprites_buffers_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:28:02 by beroux            #+#    #+#             */
/*   Updated: 2023/10/02 05:45:47 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	fill_sprite_buffers(t_data *data, t_sprites_list *sprite, double delta_angle, \
							t_player *player, t_col_buffer buffer[WIN_WIDTH]);

void	fill_sprites_buffers(t_data *data)
{
	t_sprites_list	*tmp;
	double			delta_angle;

	if (!data->sprites_list)
		return ;
	delta_angle = (data->player.fov) / WIN_WIDTH;
	tmp = data->sprites_list;
	while (tmp)
	{
		fill_sprite_buffers(data, tmp, delta_angle, &data->player, data->buffers);
		tmp = tmp->next;
	}
}

void	fill_sprite_buffers(t_data *data, t_sprites_list *sprite, double delta_angle, \
							t_player *player, t_col_buffer buffer[WIN_WIDTH])
{
	double	vec[2];
	double	vec_magn;
	double	angle;
	double	starting_vec[2];
	double	dot_product;
	int		i;
	int		j;
	int		col;
	int		slice_height;
	int		rel_width;
	int		to_fill;
	double	img_pos;

	vec[0] = (sprite->pos[0] * CELL_SIZE + (CELL_SIZE >> 1) - player->pos[0]);
	vec[1] = (sprite->pos[1] * CELL_SIZE + (CELL_SIZE >> 1) - player->pos[1]);
	starting_vec[0] = cos((player->angle.deg - (player->fov / 2)) * M_PI / 180.0f);
	starting_vec[1] = sin((player->angle.deg - (player->fov / 2)) * M_PI / 180.0f);
	vec_magn = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	dot_product = vec[0] * starting_vec[0] + vec[1] * starting_vec[1];
	angle = (acos(dot_product / vec_magn) * 180.0f) / M_PI;
	(void) buffer;
	col = angle / delta_angle;
	slice_height = (int)(CELL_SIZE / vec_magn * (WIN_HEIGHT));
	rel_width = (slice_height * sprite->sprite->height) * sprite->sprite->src->width / sprite->sprite->src->height;
	j = -rel_width / 2;
	img_pos = 0;
	while (j < rel_width / 2 && col + j < WIN_WIDTH)
	{
		i = (WIN_HEIGHT >> 1) - (slice_height >> 1) + slice_height - (slice_height >> 1);
		if (i < 0)
			i = 0;
		to_fill = 0;
		if (col + j >= 0 && col + j < WIN_WIDTH)
		{
			while (buffer[col + j].sprites[to_fill].src && to_fill < 0xf)
				to_fill++;
			buffer[col + j].sprites[to_fill].src = sprite->sprite;
			buffer[col + j].sprites[to_fill].dist = vec_magn;
			buffer[col + j].sprites[to_fill].pos = img_pos;
		}
		j++;
		img_pos += (double) sprite->sprite->src->width / (double) rel_width;
	}
	(void) data;
}
