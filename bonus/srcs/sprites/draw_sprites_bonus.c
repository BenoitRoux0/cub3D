/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 02:13:04 by beroux            #+#    #+#             */
/*   Updated: 2023/10/07 17:54:13 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_column(t_col_buffer *buffer, int col, t_uint_img *img);
static void	draw_sprite_column(t_sprite_col *sprite, int col, t_uint_img *img);

void	draw_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		draw_column(&data->buffers[i], i, data->img);
		i++;
	}
}

static void	draw_column(t_col_buffer *buffer, int col, t_uint_img *img)
{
	int		i;

	i = 0;
	while (buffer->sprites[i].src)
	{
		if (buffer->sprites[i].dist < buffer->ray.dist)
			draw_sprite_column(&buffer->sprites[i], col, img);
		i++;
	}
}

static void	draw_sprite_column(t_sprite_col *sprite, int col, t_uint_img *img)
{
	int		k;
	int		slice_height;
	double	line;

	slice_height = (int)(CELL_SIZE / sprite->dist * (WIN_HEIGHT));
	k = ((WIN_HEIGHT >> 1) - (slice_height >> 1)) + \
		slice_height - (slice_height * sprite->src->height);
	if (k < 0)
		k = 0;
	line = 0;
	while (k < WIN_HEIGHT && k < (WIN_HEIGHT >> 1) + (slice_height >> 1) && \
			line < sprite->src->src->height && \
			sprite->pos < sprite->src->src->width)
	{
		if (sprite->src->src->content[(int) line][sprite->pos] >> 24 == 0)
		{
			img->content[k][col] = \
                            sprite->src->src->content[(int) line][sprite->pos];
		}
		line += (double) sprite->src->src->height / \
				(double) slice_height * (1 / sprite->src->height);
		k++;
	}
}
