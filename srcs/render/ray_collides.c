/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collides.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:17:05 by beroux            #+#    #+#             */
/*   Updated: 2023/09/13 02:19:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ray_collide_horiz(double vector[2], t_ray *ray, t_map map)
{
	int	to_check[2];

	to_check[1] = (int) ray->inter[1] / CELL_SIZE - (vector[1] < 0);
	to_check[0] = (int) ray->inter[0] / CELL_SIZE;
	if (to_check[0] < 0 || to_check[0] >= map.size[0] || \
		to_check[1] < 0 || to_check[1] >= map.size[1])
		return (ray->hit = 0, 0);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (ray->hit = 1, 1);
	return (0);
}

int	ray_collide_vert(double vector[2], t_ray *ray, t_map map)
{
	int	to_check[2];

	to_check[0] = (int) ray->inter[0] / CELL_SIZE - (vector[0] < 0);
	to_check[1] = (int) ray->inter[1] / CELL_SIZE;
	if (to_check[0] < 0 || to_check[0] >= map.size[0] || \
		to_check[1] < 0 || to_check[1] >= map.size[1])
		return (ray->hit = 0, 0);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (ray->hit = 1, 1);
	return (0);
}
