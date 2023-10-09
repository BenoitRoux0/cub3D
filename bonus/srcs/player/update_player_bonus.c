/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:08:12 by beroux            #+#    #+#             */
/*   Updated: 2023/10/08 18:03:36 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	collide(t_data *data, double pos[2], double next_pos[2]);

int	update_player(t_data *data)
{
	double	next_pos[2];

	if (data->player.angle_mov != 0.0)
	{
		data->player.angle.deg += data->player.angle_mov * PLAYER_ROT_SPEED;
		data->player.angle.deg = fmod(data->player.angle.deg, 360);
		if (data->player.angle.deg < 0)
			data->player.angle.deg = 360 + data->player.angle.deg;
		data->player.angle.rad = (data->player.angle.deg - 90) * M_PI_4 / 45;
		data->player.angle.angle_cos = cos(data->player.angle.rad);
		data->player.angle.angle_sin = sin(data->player.angle.rad);
	}
	next_pos[0] = data->player.pos[0] + \
					(data->player.angle.angle_cos * data->player.mov[0] - \
					data->player.angle.angle_sin * data->player.mov[1]) * \
													PLAYER_SPEED * CELL_SIZE;
	next_pos[1] = data->player.pos[1] + \
					(data->player.angle.angle_sin * data->player.mov[0] + \
					data->player.angle.angle_cos * data->player.mov[1]) * \
													PLAYER_SPEED * CELL_SIZE;
	collide(data, data->player.pos, next_pos);
	data->player.pos[0] = next_pos[0];
	data->player.pos[1] = next_pos[1];
	return (0);
}

static void	collide(t_data *data, double pos[2], double next_pos[2])
{
	int	pos_in_map[2];
	int	next_pos_in_map[2];

	pos_in_map[0] = ((int)pos[0] >> CELL_SH);
	pos_in_map[1] = ((int)pos[1] >> CELL_SH);
	next_pos_in_map[0] = ((int)next_pos[0] >> CELL_SH);
	next_pos_in_map[1] = ((int)next_pos[1] >> CELL_SH);
	if (data->map.content[pos_in_map[1]][next_pos_in_map[0]] == '1')
		next_pos[0] = pos[0];
	if (data->map.content[next_pos_in_map[1]][pos_in_map[0]] == '1')
		next_pos[1] = pos[1];
	if (data->map.content[pos_in_map[1]][pos_in_map[0]] >= 'a' && \
		data->map.content[pos_in_map[1]][pos_in_map[0]] <= 'z')
		hit_sprite(data, &data->sprites_list, \
				pos_in_map, data->map.content[pos_in_map[1]][pos_in_map[0]]);
}
