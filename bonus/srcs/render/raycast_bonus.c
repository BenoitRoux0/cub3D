/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:28:49 by beroux            #+#    #+#             */
/*   Updated: 2023/10/08 16:07:32 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static t_ray	select_ray(t_ray inter_horiz, t_ray inter_vert);
static void		cast_ray(t_data *data, int i, t_angle_data *current_angle);

int	raycast(t_data *data)
{
	int				i;
	t_angle_data	current_angle;

	i = 0;
	current_angle.deg = data->player.angle.deg - ((int) data->player.fov >> 1);
	current_angle.deg = fmod((fmod(current_angle.deg, 360) + 360), 360);
	current_angle.rad = current_angle.deg * M_PI_4 / 45;
	current_angle.angle_cos = cos(current_angle.rad);
	current_angle.angle_sin = sin(current_angle.rad);
	while (i < WIN_WIDTH)
	{
		cast_ray(data, i, &current_angle);
		i++;
	}
	return (0);
}

static void	cast_ray(t_data *data, int i, t_angle_data *current_angle)
{
	t_ray	ray_horiz;
	t_ray	ray_vert;

	cast_vert(data, data->player.pos, current_angle, &ray_vert, data->map);
	cast_horiz(data, data->player.pos, current_angle, &ray_horiz, data->map);
	data->buffers[i].ray = select_ray(ray_horiz, ray_vert);
	data->buffers[i].ray.dist *= \
		cos((data->player.angle.deg - (*current_angle).deg) * M_PI_4 / 45);
	(*current_angle).deg += data->player.fov / WIN_WIDTH;
	(*current_angle).deg = fmod((fmod((*current_angle).deg, 360) + 360), 360);
	(*current_angle).rad += data->offset_raycast.rad;
	(*current_angle).angle_sin = \
				(*current_angle).angle_sin * data->offset_raycast.angle_cos + \
				(*current_angle).angle_cos * data->offset_raycast.angle_sin;
	(*current_angle).angle_cos = \
				(*current_angle).angle_cos * data->offset_raycast.angle_cos - \
				(*current_angle).angle_sin * data->offset_raycast.angle_sin;
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
