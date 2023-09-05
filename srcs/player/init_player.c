/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:10:30 by beroux            #+#    #+#             */
/*   Updated: 2023/08/18 18:57:51 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_player	init_player(enum e_dir dir, int pos[2])
{
	t_player	player;

	player.angle = dir * 90;
	player.pos[0] = (float) pos[0] * CELL_SIZE + (float) CELL_SIZE / 2;
	player.pos[1] = (float) pos[1] * CELL_SIZE + (float) CELL_SIZE / 2;
	player.mov[0] = 0;
	player.mov[1] = 0;
	player.angle_mov = 0;
	player.fov = PLAYER_FOV;
	return (player);
}