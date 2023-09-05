/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:08:12 by beroux            #+#    #+#             */
/*   Updated: 2023/09/03 03:52:11 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	update_player(t_data *data)
{
	data->player.angle += data->player.angle_mov * PLAYER_SPEED;
	data->player.angle = fmod(data->player.angle, 360);
	if (data->player.angle < 0)
		data->player.angle = 360 + data->player.angle;
	data->player.pos[0] += (cos((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[0] - sin((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[1]) * PLAYER_SPEED;
	data->player.pos[1] += (sin((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[0] + cos((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[1]) * PLAYER_SPEED;
	return (0);
}
