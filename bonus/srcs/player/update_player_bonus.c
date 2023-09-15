/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:08:12 by beroux            #+#    #+#             */
/*   Updated: 2023/09/14 18:03:13 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	collide(t_data *data, double pos[2], double next_pos[2]);

int	update_player(t_data *data)
{
	double	next_pos[2];

	data->player.angle += data->player.angle_mov * PLAYER_SPEED;
	data->player.angle = fmod(data->player.angle, 360);
	if (data->player.angle < 0)
		data->player.angle = 360 + data->player.angle;
	next_pos[0] = data->player.pos[0] + \
							(cos((data->player.angle - 90) * M_PI_4 / 45) * \
														data->player.mov[0] - \
							sin((data->player.angle - 90) * M_PI_4 / 45) * \
														data->player.mov[1]) * \
																PLAYER_SPEED;
	next_pos[1] = data->player.pos[1] + \
							(sin((data->player.angle - 90) * M_PI_4 / 45) * \
														data->player.mov[0] + \
							cos((data->player.angle - 90) * M_PI_4 / 45) * \
														data->player.mov[1]) * \
																PLAYER_SPEED;
	collide(data, data->player.pos, next_pos);
	data->player.pos[0] = next_pos[0];
	data->player.pos[1] = next_pos[1];
	return (0);
}

static void	collide(t_data *data, double pos[2], double next_pos[2])
{
	int pos_in_map[2];
	int	next_pos_in_map[2];

	pos_in_map[0] = (int) (pos[0] / CELL_SIZE);
	pos_in_map[1] = (int) (pos[1] / CELL_SIZE);
	next_pos_in_map[0] = (int) (next_pos[0] / CELL_SIZE);
	next_pos_in_map[1] = (int) (next_pos[1] / CELL_SIZE);
	if (data->map.content[pos_in_map[1]][next_pos_in_map[0]] == '1')
		next_pos[0] = pos[0];
	if (data->map.content[next_pos_in_map[1]][pos_in_map[0]] == '1')
		next_pos[1] = pos[1];
}
