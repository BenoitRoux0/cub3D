/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 02:13:04 by beroux            #+#    #+#             */
/*   Updated: 2023/10/03 14:27:40 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	draw_sprites(t_data *data)
{
	int i;
	int	j;
	int k;
	double	line;
	int slice_height;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (data->buffers[i].sprites[j].src)
		{
			if (data->buffers[i].sprites[j].dist < data->buffers[i].ray.dist)
			{
				slice_height = (int)(CELL_SIZE / data->buffers[i].sprites[j].dist * (WIN_HEIGHT));
				k = ((WIN_HEIGHT >> 1) - (slice_height >> 1)) + slice_height - (slice_height * data->buffers[i].sprites[j].src->height);
				if (k < 0)
					k = 0;
				line = 0;
				while (k < WIN_HEIGHT && k < (WIN_HEIGHT >> 1) + (slice_height >> 1) && line < data->buffers[i].sprites[j].src->src->height && data->buffers[i].sprites[j].pos < data->buffers[i].sprites[j].src->src->width)
				{
					if (uint32_t_to_color(data->buffers[i].sprites[j].src->src->content[(int) line][data->buffers[i].sprites[j].pos]).a == 0)
						data->img->content[k][i] = data->buffers[i].sprites[j].src->src->content[(int) line][data->buffers[i].sprites[j].pos];
					line += (double) data->buffers[i].sprites[j].src->src->height / \
							(double) slice_height * 2;
					k++;
				}
			}
			j++;
		}
		i++;
	}
}
