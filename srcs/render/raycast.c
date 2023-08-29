/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:28:49 by beroux            #+#    #+#             */
/*   Updated: 2023/08/26 18:21:47 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef int (*t_collide_check_func)(double[2], t_ray, t_map);

static int		cast_vert(double start[2], double angle, t_ray *ray, t_map map);
static int		cast_horiz(double start[2], double angle, t_ray *ray, t_map map);
static t_ray	dda(double start[2], double vector[2], t_map map, t_collide_check_func ray_collide);
static int		ray_collide_horiz(double vector[2], t_ray ray, t_map map);
static int		ray_collide_vert(double vector[2], t_ray ray, t_map map);

int	raycast(t_data *data)
{
	int		i;
	double	current_angle;
	t_ray	ray_horiz;
	t_ray	ray_vert;

	i = 0;
	current_angle = data->player.angle - (data->player.fov / 2);
	current_angle = fmod((fmod(current_angle, 360) + 360), 360);
//	current_angle = data->player.angle;
//	printf("player angle: %f\n", data->player.angle);
//	printf("player pos: %f %f\n", data->player.pos[0], data->player.pos[1]);
	while (i < WIN_WIDTH)
	{
		cast_vert(data->player.pos, current_angle, &ray_vert, data->map);
		cast_horiz(data->player.pos, current_angle, &ray_horiz, data->map);
		data->rays[i] = ray_horiz;
		current_angle += data->player.fov / WIN_WIDTH;
		current_angle = fmod((fmod(current_angle, 360) + 360), 360);
		i++;
	}
	return (0);
}

static int	cast_vert(double start[2], double angle, t_ray *ray, t_map map)
{
	t_ray	inter_vert;
	double	rad;
	double 	vector[2];

	angle = fmod(angle, 360);
	rad = angle * M_PI_4 / 45;
	inter_vert.inter[0] = ((double) CELL_SIZE) * ((int)(start[0] / CELL_SIZE) + (angle < 90 || angle > 270));
	inter_vert.dist = fabs(inter_vert.inter[0] - start[0]) / cos(rad);
	inter_vert.inter[1] = start[1] + inter_vert.dist * sin(rad);
	vector[0] =  CELL_SIZE - 2 * CELL_SIZE * (angle > 90 && angle < 270);
	vector[1] = (CELL_SIZE / (start[0] - inter_vert.inter[0])) * (start[1] - inter_vert.inter[1]);
//	printf("vert vector %f %f\n", vector[0], vector[1]);
	*ray = dda(inter_vert.inter, vector, map, ray_collide_vert);
	ray->dist += sqrt(pow(start[0] - inter_vert.inter[0], 2) + pow(start[1] - inter_vert.inter[1], 2));
	return (0);
}

static int	cast_horiz(double start[2], double angle, t_ray *ray, t_map map)
{
	t_ray	inter_horiz;
	double	rad;
	double	vector[2];

	(void) map;
	(void) ray;
	if (angle < 0 || angle > 360)
		return (printf("angle error: %f\n", angle));
	rad = angle * M_PI_4 / 45;
	inter_horiz.inter[1] = (double) CELL_SIZE * ((int)(start[1] / CELL_SIZE) - (angle < 180) - (fmod(start[1], CELL_SIZE) == 0 && angle > 180) + (fmod(start[1], CELL_SIZE) == 0 && angle <= 180));
	inter_horiz.dist = (inter_horiz.inter[1] - start[1]) / sin(rad);
	inter_horiz.inter[0] = fabs(inter_horiz.dist * cos(rad));
	if (angle > 90 && angle < 270)
		inter_horiz.inter[0] *= -1;
	inter_horiz.inter[0] += start[0];
	vector[1] = CELL_SIZE - 2 * CELL_SIZE * (angle > 180);
	vector[0] = fabs((CELL_SIZE / (start[1] - inter_horiz.inter[1])) * (inter_horiz.inter[0] - start[0]));
	if (angle > 90 && angle < 270)
		vector[0] *= -1;
	if (vector[0] > 0)
		printf("vector x > 0\n");
//	printf("horiz vector: %f %f\n", vector[0], vector[1]);
	*ray = dda(inter_horiz.inter, vector, map, ray_collide_horiz);
	return (0);
}
static t_ray	dda(double start[2], double vector[2], t_map map, t_collide_check_func ray_collide)
{
	int		nb_iter;
	int		hit;
	t_ray	ray;
	double	vec_magnitude;

//	printf("vector: %f %f\n", vector[0], vector[1]);
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

static int	ray_collide_horiz(double vector[2], t_ray ray, t_map map)
{
	int	to_check[2];

	(void) vector;
	to_check[1] = (int) ray.inter[1] / CELL_SIZE - (vector[1] < 0);
	to_check[0] = (int) (ray.inter[0]) / CELL_SIZE;// - (vector[0] < 0);
	if (to_check[0] < 0 || to_check[0] >= map.size[0] || \
		to_check[1] < 0 || to_check[1] >= map.size[1])
		return (/*printf("horiz hit in %d %d\n", to_check[0], to_check[1]), */1);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (/*printf("horiz hit in %d %d\n", to_check[0], to_check[1]), */1);
	return (0);
}

static int	ray_collide_vert(double vector[2], t_ray ray, t_map map)
{
	int	to_check[2];

	to_check[0] = (int) ray.inter[0] / CELL_SIZE - (vector[0] < 0);
	to_check[1] = (int) ((ray.inter[1] + CELL_SIZE) / CELL_SIZE);
	if (to_check[0] < 0 || to_check[0] >= map.size[0] || \
			to_check[1] < 0 || to_check[1] >= map.size[1])
		return (/*printf("vert hit in %d %d\n", to_check[0], to_check[1]), */1);
	if (map.content[to_check[1]][to_check[0]] == '1')
		return (/*printf("vert hit in %d %d\n", to_check[0], to_check[1]), */1);
	return (0);
}