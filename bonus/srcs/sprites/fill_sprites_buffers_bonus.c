/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprites_buffers_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:28:02 by beroux            #+#    #+#             */
/*   Updated: 2023/10/05 05:32:08 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	fill_sprite_buffers(t_data *data, t_sprites_list *sprite, \
								double delta_angle, t_player *player);
static bool	neg_angle(t_data *data, double point[2], double angle);

static void	foo(t_sprites_list *sprite, t_col_buffer *buffer, double vec_magn, \
		int col);

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
		fill_sprite_buffers(data, tmp, delta_angle, &data->player);
		tmp = tmp->next;
	}
}

static void	fill_sprite_buffers(t_data *data, t_sprites_list *sprite, \
								double delta_angle, t_player *player)
{
	double	vec[2];
	double	starting_vec[2];
	double	vec_magn;
	double	angle;
	double	dot_product;

	vec[0] = (sprite->pos[0] * CELL_SIZE + (CELL_SIZE / 2) - player->pos[0]);
	vec[1] = (sprite->pos[1] * CELL_SIZE + (CELL_SIZE / 2) - player->pos[1]);
	starting_vec[0] = cos((player->angle.deg - \
							(player->fov / 2)) * M_PI / 180.0f);
	starting_vec[1] = sin((player->angle.deg - \
							(player->fov / 2)) * M_PI / 180.0f);
	vec_magn = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	dot_product = vec[0] * starting_vec[0] + vec[1] * starting_vec[1];
	angle = (acos(dot_product / vec_magn) * 180.0f) / M_PI;
	if (neg_angle(data, vec, angle))
		angle *= -1;
	foo(sprite, data->buffers, vec_magn, angle / delta_angle);
}

static void	foo(t_sprites_list *sprite, t_col_buffer *buffer, double vec_magn, \
		int col)
{
	int		i;
	double	img_pos;
	int		to_fill;
	int		slice_height;
	int		rel_width;

	slice_height = (int)(CELL_SIZE / vec_magn * (WIN_HEIGHT));
	rel_width = (slice_height * sprite->sprite->height) * \
				sprite->sprite->src->width / sprite->sprite->src->height;
	i = -rel_width / 2;
	img_pos = 0;
	while (i < rel_width / 2 && col + i < WIN_WIDTH)
	{
		to_fill = 0;
		if (col + i >= 0 && col + i < WIN_WIDTH)
		{
			while (buffer[col + i].sprites[to_fill].src && to_fill < 0xf)
				to_fill++;
			buffer[col + i].sprites[to_fill].src = sprite->sprite;
			buffer[col + i].sprites[to_fill].dist = vec_magn;
			buffer[col + i].sprites[to_fill].pos = img_pos;
		}
		i++;
		img_pos += (double) sprite->sprite->src->width / (double) rel_width;
	}
}

static bool	neg_angle(t_data *data, double point[2], double angle)
{
	double	vec[2];
	double	vec_magn;
	double	dot_product;
	double	angle_center;

	vec[0] = point[0];
	vec[1] = point[1];
	vec_magn = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
	dot_product = vec[0] * -data->player.angle.angle_sin + \
					vec[1] * data->player.angle.angle_cos;
	angle_center = (acos(dot_product / vec_magn) * 180.0f) / M_PI;
	if (angle < data->player.fov / 2 && angle_center > data->player.fov / 2)
		return (true);
	return (false);
}
