/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:56 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/15 18:26:33 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	mouse_motion(int x, int y, t_data *data)
{
	if (data->mouse_listen)
	{
		data->player.angle_mov += x - WIN_WIDTH / 2;
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (y);
}
