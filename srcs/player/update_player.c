/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:08:12 by beroux            #+#    #+#             */
/*   Updated: 2023/08/18 19:04:20 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	update_player(t_data *data)
{
	printf("update player\n");
	data->player.angle += data->player.angle_mov;
	printf("mov: %f %f\n", data->player.mov[0], data->player.mov[1]);
	data->player.pos[0] += cos((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[0] - sin((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[1];
	data->player.pos[1] += sin((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[0] + cos((data->player.angle - 90) * M_PI_4 / 45) * data->player.mov[1];
	return (0);
}
