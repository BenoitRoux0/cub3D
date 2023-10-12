/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:26:36 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 18:50:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_uint_img	*select_tex(t_ray *ray, t_data *data)
{
	int		to_check[2];
	double	vector[2];

	vector[0] = data->player.pos[0] - ray->inter[0];
	vector[1] = data->player.pos[1] - ray->inter[1];
	to_check[0] = ((int) ray->inter[0] >> CELL_SH);
	to_check[1] = ((int) ray->inter[1] >> CELL_SH);
	if (fmod(ray->inter[0], CELL_SIZE) == 0 && vector[0] > 0)
		to_check[0]--;
	if (fmod(ray->inter[1], CELL_SIZE) == 0 && vector[1] > 0)
		to_check[1]--;
	if (data->map.content[to_check[1]][to_check[0]] == 'D' && \
		data->doors_map.content[to_check[1]][to_check[0]])
		return (data->map.door);
	else if (data->map.content[to_check[1]][to_check[0]] == 'D' && \
			data->doors_map.content[to_check[1]][to_check[0]] == 0)
		return (NULL);
	if (fmod(ray->inter[0], CELL_SIZE) == 0 && vector[0] > 0)
		return (data->map.walls_text[WEST]);
	else if (fmod(ray->inter[0], CELL_SIZE) == 0 && vector[0] < 0)
		return (data->map.walls_text[EAST]);
	else if (fmod(ray->inter[1], CELL_SIZE) == 0 && vector[1] > 0)
		return (data->map.walls_text[NO]);
	return (data->map.walls_text[SO]);
}
