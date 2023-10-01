/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_angles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:47:08 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 15:53:01 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	init_angles(t_data *data)
{
	data->offset_raycast.deg = data->player.fov / WIN_WIDTH;
	data->offset_raycast.rad = data->offset_raycast.deg * M_PI_4 / 45;
	data->offset_raycast.angle_cos = cos(data->offset_raycast.rad);
	data->offset_raycast.angle_sin = sin(data->offset_raycast.rad);
	data->offset_start.deg = (data->player.fov / 2);
	data->offset_start.rad = data->offset_start.deg * M_PI_4 / 45;
	data->offset_start.angle_cos = cos(data->offset_start.rad);
	data->offset_start.angle_sin = sin(data->offset_start.rad);
}
