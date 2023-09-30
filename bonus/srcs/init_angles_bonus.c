/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_angles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:47:08 by beroux            #+#    #+#             */
/*   Updated: 2023/09/30 15:38:28 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	init_angles(t_data *data)
{
	data->offset_raycast.deg = data->player.fov / WIN_WIDTH;
	data->offset_raycast.rad = data->offset_raycast.deg * M_PI_4 / 45;
	data->offset_raycast.angle_cos = cos(data->offset_raycast.rad);
	data->offset_raycast.angle_sin = sin(data->offset_raycast.rad);
	data->offset_start.deg = ((int) data->player.fov >> 1);
	data->offset_start.rad = data->offset_start.deg * M_PI_4 / 45;
	data->offset_start.angle_cos = cos(data->offset_start.rad);
	data->offset_start.angle_sin = sin(data->offset_start.rad);
}