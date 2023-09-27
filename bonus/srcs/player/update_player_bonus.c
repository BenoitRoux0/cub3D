/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:08:12 by beroux            #+#    #+#             */
/*   Updated: 2023/09/26 18:31:19 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	update_player(t_data *data)
{
	double	next_pos[2];
	double	rad;
	double	angle_cos;
	double	angle_sin;

	rad = (data->player.angle - 90) * M_PI_4 / 45;
	angle_cos = cos(rad);
	angle_sin = sin(rad);
	data->player.angle += data->player.angle_mov * PLAYER_SPEED;
	data->player.angle = fmod(data->player.angle, 360);
	if (data->player.angle < 0)
		data->player.angle = 360 + data->player.angle;
	next_pos[0] = data->player.pos[0] + (angle_cos * data->player.mov[0] - \
										angle_sin * data->player.mov[1]) * \
																PLAYER_SPEED;
	next_pos[1] = data->player.pos[1] + (angle_sin * data->player.mov[0] + \
										angle_cos * data->player.mov[1]) * \
																PLAYER_SPEED;
	collide(data, data->player.pos, next_pos);
	data->player.pos[0] = next_pos[0];
	data->player.pos[1] = next_pos[1];
	return (0);
}
