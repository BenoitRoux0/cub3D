/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:16 by beroux            #+#    #+#             */
/*   Updated: 2023/09/19 14:46:00 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	put_rotated_point(t_data *data, int dst_pos[2], \
								int plr_pos[2], int color);
static void	put_row(t_data *data, int row, int pos[2]);

t_uint_img	*create_map(t_map map)
{
	t_uint_img	*map_img;
	int			i;
	int			j;

	map_img = init_img(map.size.x * 16, map.size.y * 16);
	i = 0;
	while (i < map_img->height)
	{
		j = 0;
		while (j < map_img->width)
		{
			map_img->content[i][j] = 0xFFFFFF * \
										(map.content[i / 16][j / 16] == '1');
			j++;
		}
		i++;
	}
	return (map_img);
}

void	minimap_draw(t_data *data)
{
	int		i;
	int		pos[2];
	double	ratio;

	ratio = data->map.size.x * CELL_SIZE / data->map_img->width;
	pos[0] = ((data->player.pos[0])) / ratio;
	pos[1] = ((data->player.pos[1])) / ratio;
	i = 0;
	while (i < data->minimap_size.y)
	{
		put_row(data, i, pos);
		i++;
	}
}

static void	put_row(t_data *data, int row, int pos[2])
{
	int	i;

	i = 0;
	while (i < data->minimap_size.x)
	{
		if (pow(i - 100, 2) + pow(row - 100, 2) < 100 * 100)
		{
			if (pow(i - 100, 2) + pow(row - 100, 2) < 95 * 95)
				put_rotated_point(data, (int [2]){i, row}, pos, \
						~data->map.colors[CEILING]);
			else
				data->img->content[row][i] = \
										data->map.colors[CEILING] + 0XF0F0F0;
		}
		if (pow(i - 100, 2) + pow(row - 100, 2) < 25 && \
			row < data->img->height && i < data->img->width)
			data->img->content[row][i] = 0XFF0000;
		i++;
	}
}

static void	put_rotated_point(t_data *data, int dst_pos[2], \
								int pos[2], int color)
{
	int				x;
	int				y;
	t_angle_data	angle_data;
	int				src_pos[2];

	src_pos[0] = pos[0] + dst_pos[0] - data->minimap_size.x / 2;
	src_pos[1] = pos[1] + dst_pos[1] - data->minimap_size.y / 2;
	angle_data.rad = ((data->player.angle + 90) * M_PI_4 / 45);
	angle_data.angle_cos = cos(angle_data.rad);
	angle_data.angle_sin = sin(angle_data.rad);
	x = (src_pos[0] - pos[0]) * angle_data.angle_cos - \
		(src_pos[1] - pos[1]) * angle_data.angle_sin + pos[0];
	y = (src_pos[0] - pos[0]) * angle_data.angle_sin + \
		(src_pos[1] - pos[1]) * angle_data.angle_cos + pos[1];
	if (x >= 0 && x < data->map_img->width && \
		y >= 0 && y < data->map_img->height && data->map_img->content[y][x])
		data->img->content[dst_pos[1]][dst_pos[0]] = color;
	else
		data->img->content[dst_pos[1]][dst_pos[0]] = ~color - 0XF0F0F0;
}
