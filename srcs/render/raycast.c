/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:28:49 by beroux            #+#    #+#             */
/*   Updated: 2023/10/09 09:21:08 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef int	(*t_collide_check_func)(double[2], t_ray *, t_map);

static int		cast_vert(double start[2], double angle, t_ray *ray, t_map map);
static int		cast_horiz(double start[2], double a, t_ray *ray, t_map map);
static t_ray	dda(t_ray s, double vector[2], t_map m, t_collide_check_func c);
static t_ray	select_ray(t_ray inter_horiz, t_ray inter_vert);

int	raycast(t_data *data)
{
	int		i;
	double	current_angle;
	t_ray	ray_horiz;
	t_ray	ray_vert;

	i = 0;
	current_angle = data->player.angle - (data->player.fov / 2);
	current_angle = fmod((fmod(current_angle, 360) + 360), 360);
	while (i < WIN_WIDTH)
	{
		cast_vert(data->player.pos, current_angle, &ray_vert, data->map);
		cast_horiz(data->player.pos, current_angle, &ray_horiz, data->map);
		data->rays[i] = select_ray(ray_horiz, ray_vert);
		data->rays[i].dist *= \
						cos((data->player.angle - current_angle) * M_PI_4 / 45);
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
	double	vector[2];

	rad = angle * M_PI_4 / 45;
	if (angle == 90 || angle == 270)
		return (*ray = (t_ray){{INFINITY, start[1]}, INFINITY, 0}, 0);
	inter_vert.inter[0] = ((double) CELL_SIZE) * (((int)start[0] / CELL_SIZE) + \
			(angle < 90 || angle > 270) - \
			(fabs(fmod(start[0], CELL_SIZE)) <= 0.0001 && \
						(angle > 90 && angle < 270)) + \
			(fabs(fmod(start[0], CELL_SIZE) - CELL_SIZE) <= 0.0001 && \
						(angle <= 90 || angle >= 270)));
	inter_vert.dist = (inter_vert.inter[0] - start[0]) / cos(rad);
	inter_vert.inter[1] = (inter_vert.dist * sin(rad));
	inter_vert.inter[1] += start[1];
	vector[0] = CELL_SIZE - 2 * CELL_SIZE * (angle > 90 && angle < 270);
	vector[1] = (CELL_SIZE / (start[0] - inter_vert.inter[0])) * \
								(inter_vert.inter[1] - start[1]);
	if (angle < 90 || angle > 270)
		vector[1] *= -1;
	*ray = dda(inter_vert, vector, map, ray_collide_vert);
	return (0);
}

static int	cast_horiz(double start[2], double angle, t_ray *ray, t_map map)
{
	t_ray	inter_horiz;
	double	rad;
	double	vector[2];

	rad = angle * M_PI_4 / 45;
	if (angle == 0 || angle == 180)
		return (*ray = (t_ray){{INFINITY, start[1]}, INFINITY, 0}, 0);
	inter_horiz.inter[1] = (double) CELL_SIZE * (((int)start[1] / CELL_SIZE) + \
			(angle < 180) + \
			(fabs(fmod(start[1], CELL_SIZE) - CELL_SIZE) <= 0.0001 && \
							angle < 180) - \
			(fmod(start[1], CELL_SIZE) <= 0.0001 && \
							angle > 180));
	inter_horiz.dist = (inter_horiz.inter[1] - start[1]) / sin(rad);
	inter_horiz.inter[0] = (inter_horiz.dist * cos(rad));
	inter_horiz.inter[0] += start[0];
	vector[1] = CELL_SIZE - 2 * CELL_SIZE * (angle > 180);
	vector[0] = fabs((CELL_SIZE / (start[1] - inter_horiz.inter[1])) * \
									(inter_horiz.inter[0] - start[0]));
	if (angle > 90 && angle < 270)
		vector[0] *= -1;
	*ray = dda(inter_horiz, vector, map, ray_collide_horiz);
	return (0);
}

static t_ray	dda(t_ray r, double v[2], t_map m, t_collide_check_func c)
{
	int		nb_iter;
	int		hit;
	double	vec_magnitude;

	r.hit = 0;
	nb_iter = 0;
	r.dist = fabs(r.dist);
	hit = c(v, &r, m);
	vec_magnitude = sqrt(v[0] * v[0] + v[1] * v[1]);
	while (!hit && nb_iter < INTER_LIM)
	{
		r.inter[0] += v[0];
		r.inter[1] += v[1];
		r.dist += vec_magnitude;
		hit = c(v, &r, m);
		nb_iter++;
	}
	return (r);
}

static t_ray	select_ray(t_ray inter_horiz, t_ray inter_vert)
{
	if (inter_horiz.hit && !inter_vert.hit)
		return (inter_horiz);
	if (inter_vert.hit && !inter_horiz.hit)
		return (inter_vert);
	if (inter_horiz.dist < inter_vert.dist)
		return (inter_horiz);
	return (inter_vert);
}
