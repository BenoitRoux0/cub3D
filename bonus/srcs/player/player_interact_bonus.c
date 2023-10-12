/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interact_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:58:35 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 18:33:43 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	player_interact(t_data *data)
{
	double	pos[2];
	int		pos_in_map[2];

	pos[0] = data->player.pos[0] + -data->player.angle.angle_sin * \
						(CELL_SIZE);
	pos[1] = data->player.pos[1] + data->player.angle.angle_cos * \
						(CELL_SIZE);
	pos_in_map[0] = ((int)pos[0] >> CELL_SH);
	pos_in_map[1] = ((int)pos[1] >> CELL_SH);
	if (data->map.content[pos_in_map[1]][pos_in_map[0]] == 'D')
	{
		if (data->doors_map.content[pos_in_map[1]][pos_in_map[0]] == 100)
			data->doors_map.content[pos_in_map[1]][pos_in_map[0]] = 0;
		else if (pos_in_map[0] != ((int)data->player.pos[0] >> CELL_SH) || \
					pos_in_map[1] != ((int)data->player.pos[1] >> CELL_SH))
			data->doors_map.content[pos_in_map[1]][pos_in_map[0]] = 100;
	}
}
