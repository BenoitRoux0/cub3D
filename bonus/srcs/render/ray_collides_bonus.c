/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collides.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:17:05 by beroux            #+#    #+#             */
/*   Updated: 2023/10/04 10:01:28 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	ray_collide_horiz(t_data *data, double vector[2], t_ray *ray, t_map map)
{
	int	to_check[2];

	to_check[1] = ((int) ray->inter[1] >> CELL_SH) - (vector[1] < 0);
	to_check[0] = ((int) ray->inter[0] >> CELL_SH);
	if (to_check[0] < 0 || to_check[0] >= map.size.x || \
		to_check[1] < 0 || to_check[1] >= map.size.y)
		return (ray->hit = 0, 0);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (ray->hit = 1, 1);
	if (map.content[to_check[1]][to_check[0]] >= 'a' && \
		map.content[to_check[1]][to_check[0]] <= 'z')
		hit_sprite(data, &data->sprites_list, \
					to_check, map.content[to_check[1]][to_check[0]]);
	return (0);
}

int	ray_collide_vert(t_data *data, double vector[2], t_ray *ray, t_map map)
{
	int	to_check[2];

	to_check[0] = ((int) ray->inter[0] >> CELL_SH) - (vector[0] < 0);
	to_check[1] = ((int) ray->inter[1] >> CELL_SH);
	if (to_check[0] < 0 || to_check[0] >= map.size.x || \
		to_check[1] < 0 || to_check[1] >= map.size.y)
		return (ray->hit = 0, 0);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (ray->hit = 1, 1);
	if (map.content[to_check[1]][to_check[0]] >= 'a' && \
		map.content[to_check[1]][to_check[0]] <= 'z')
		hit_sprite(data, &data->sprites_list, \
					to_check, map.content[to_check[1]][to_check[0]]);
	return (0);
}
