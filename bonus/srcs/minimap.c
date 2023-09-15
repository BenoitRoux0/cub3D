/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:05:16 by beroux            #+#    #+#             */
/*   Updated: 2023/09/14 19:39:37 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

t_uint_img	*cut_minimap(t_data *data)
{
	t_uint_img	*minimap;
	int 		pos[2];

	pos[0] = (int) (data->player.pos[0] / CELL_SIZE * 16) - (data->minimap_size.x) / 2;
	pos[1] = (int) (data->player.pos[1] / CELL_SIZE * 16) - (data->minimap_size.y) / 2;
	printf("pos in map: %d %d\n", pos[0], pos[1]);
	minimap = ft_sub_img(data->map_img, pos, data->minimap_size.x, data->minimap_size.y);
	return (minimap);
}