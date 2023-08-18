/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:28:49 by beroux            #+#    #+#             */
/*   Updated: 2023/08/16 05:28:04 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		cast_vert(double start[2], double angle, t_ray *ray, t_map map);
static int		cast_horiz(double start[2], double angle, t_ray *ray, t_map map);
static t_ray	dda(double start[2], double vector[2], t_map map);
static int		ray_collide(double vector[2], t_ray ray, t_map map);

int	raycast(t_data *data)
{
	int		i;
	double	current_angle;

	i = 0;
	current_angle = data->player.angle - (data->player.fov / 2);
	while (i < WIN_WIDTH)
	{
		cast_vert(data->player.pos, current_angle, data->rays + i, data->map);
		cast_horiz(data->player.pos, current_angle, data->rays + i, data->map);
		current_angle += data->player.fov / WIN_WIDTH;
		i++;
	}
	return (0);
}

static int	cast_vert(double start[2], double angle, t_ray *ray, t_map map)
{
	t_ray	inter_vert;
	double	rad;
	double 	vector[2];

	rad = angle * M_PI_4 / 45;
	inter_vert.inter[0] = ((double) CELL_SIZE) * ((int)(start[0] / CELL_SIZE) + (angle < 90 || angle > 270) - ((angle > 90 && angle < 270) && fmod(start[0], CELL_SIZE) < 0.01));
	inter_vert.dist = fabs(inter_vert.inter[0] - start[0]) / cos(rad);
	inter_vert.inter[1] = start[1] + inter_vert.dist * sin(rad);
	vector[0] = inter_vert.inter[0] - start[0];
	vector[1] = (CELL_SIZE / (inter_vert.inter[0] - start[0])) * (inter_vert.inter[1] - start[1]);
	*ray = dda(inter_vert.inter, vector, map);
	return (0);
}

static int	cast_horiz(double start[2], double angle, t_ray *ray, t_map map)
{
	t_ray	inter_horiz;
	double	rad;
	double	vector[2];

	(void) map;
	(void) ray;
	rad = angle * M_PI_4 / 45;
	inter_horiz.inter[1] = (double ) CELL_SIZE * ((int)(start[1] / CELL_SIZE) + (angle < 180) - ((angle > 180) && fmod(start[1], CELL_SIZE) < 0.01));
	inter_horiz.dist = fabs(inter_horiz.inter[1] - start[1]) / sin(rad);
	inter_horiz.inter[0] = start[0] + inter_horiz.dist * cos(rad);
	vector[1] = inter_horiz.inter[1] - start[1];
	vector[0] = (CELL_SIZE / (inter_horiz.inter[1] - start[1])) * (inter_horiz.inter[0] - start[0]);
	*ray = dda(inter_horiz.inter, vector, map);
	return (0);
}

static t_ray dda(double start[2], double vector[2], t_map map)
{
	int		nb_iter;
	int		hit;
	t_ray	ray;
	double	vec_magnitude;

	nb_iter = 0;
	ray.inter[0] = start[0];
	ray.inter[1] = start[1];
	ray.dist = 0;
	hit = ray_collide(vector, ray, map);
	vec_magnitude = sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
	while (!hit && nb_iter < INTER_LIM)
	{
		ray.inter[0] += vector[0];
		ray.inter[1] += vector[1];
		ray.dist += vec_magnitude;
		hit = ray_collide(vector, ray, map);
		nb_iter++;
	}
	return (ray);
}

static int	ray_collide(double vector[2], t_ray ray, t_map map)
{
	int	to_check[2];

	if (fmod(ray.inter[0], CELL_SIZE) < 0.01)
	{
		to_check[0] = (int) ray.inter[0] / CELL_SIZE - (vector[0] < 0);
		to_check[1] = (int) (ray.inter[1] + CELL_SIZE) / CELL_SIZE;
		if (to_check[0] < 0 || to_check[0] >= map.size[0] || to_check[1] < 0 \
			|| to_check[1] >= map.size[1])
			return (1);
		if (map.content[to_check[1]][to_check[0]] == '1')
			return (1);
	}
	else
	{
		to_check[1] = (int) ray.inter[1] / CELL_SIZE + (vector[1] > 0);
		to_check[0] = (int) (ray.inter[0] + CELL_SIZE) / CELL_SIZE;
		if (to_check[0] < 0 || to_check[0] >= map.size[0] || to_check[1] < 0 \
			|| to_check[1] >= map.size[1])
			return (1);
		if (map.content[to_check[1]][to_check[0]] == '1')
			return (1);
	}
	return (0);
}
