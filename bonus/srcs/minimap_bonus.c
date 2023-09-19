/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:16 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 17:12:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

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

void	minimap_draw(t_data * data)
{
	int 		pos[2];
	int			i;
	int			j;
	int 		new_i;
	int 		new_j;
	double		rad;
	double		cos_ret;
	double		sin_ret;

	pos[0] = (int) (data->player.pos[0] / CELL_SIZE * 16) - (data->minimap_size.x) / 2;
	pos[1] = (int) (data->player.pos[1] / CELL_SIZE * 16) - (data->minimap_size.y) / 2;
	rad = (data->player.angle - 90) * M_PI_4 / 45;
	cos_ret = -cos(rad);
	sin_ret = sin(rad);
	i = 0;
	while (i < data->img->height && i < data->minimap_size.y)
	{
		j = 0;
		while (j < data->img->width && j < data->minimap_size.x)
		{
			if ((pow(i - 100, 2) + pow(j - 100, 2)) < 100 * 100)
			{
				new_j = (int) (cos_ret * (double) (j - 100) - sin_ret * (double) (i - 100)) + 100;
				new_i = (int) (sin_ret * (double) (j - 100) + cos_ret * (double) (i - 100)) + 100;
				if (!(i + pos[1] < 0 || j + pos[0] < 0 || \
                i + pos[1] >= data->map_img->height ||
					j + pos[0] >= data->map_img->width) && data->map_img->content[i + pos[1]][j + pos[0]])
					data->img->content[new_i][new_j] = data->map_img->content[i + pos[1]][j + pos[0]];
			}
			j++;
		}
		i++;
	}
}

void	minimap_draw_player(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->minimap_size.y)
	{
		j = 0;
		while (j < data->minimap_size.x)
		{
//			printf("dist square = %f\n", (pow(i - data->minimap_size.y / 2, 2) + pow(j - data->minimap_size.x / 2, 2)));
			if ((pow(i - data->minimap_size.y / 2, 2) + pow(j - data->minimap_size.x / 2, 2)) < 25)
				data->img->content[i][j] = 0XFF0000;
			j++;
		}
		i++;
	}
}
