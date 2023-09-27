/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:10:30 by beroux            #+#    #+#             */
/*   Updated: 2023/09/27 23:41:56 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_player	init_player(enum e_dir dir, t_vec_2i pos)
{
	t_player	player;

	player.angle.deg = dir * 90;
	player.angle.deg = fmod(player.angle.deg, 360);
	if (player.angle.deg < 0)
		player.angle.deg = 360 + player.angle.deg;
	player.angle.rad = (player.angle.deg - 90) * M_PI_4 / 45;
	player.angle.angle_cos = cos(player.angle.rad);
	player.angle.angle_sin = sin(player.angle.rad);
	player.pos[0] = (float) pos.x * CELL_SIZE + (float) CELL_SIZE / 2;
	player.pos[1] = (float) pos.y * CELL_SIZE + (float) CELL_SIZE / 2;
	player.mov[0] = 0;
	player.mov[1] = 0;
	player.angle_mov = 0;
	player.fov = PLAYER_FOV;
	return (player);
}
