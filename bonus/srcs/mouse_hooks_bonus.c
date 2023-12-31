/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:15:59 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 16:38:35 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	on_mouse_clic(int button, int x, int y, t_data *data)
{
	if (button == 1 && data->input_mode == keyboard_mouse)
		data->weapon.animation = true;
	(void)x;
	(void)y;
	return (0);
}

int	on_mouvement(int x, int y, t_data *data)
{
	if (data->input_mode == keyboard_mouse && data->win_focused)
	{
		data->mouse.x = x;
		data->mouse.y = y;
		data->player.angle_mov = (data->mouse.x - (WIN_WIDTH >> 1)) * 0.025;
	}
	return (0);
}

int	on_focus_in(t_data *data)
{
	data->win_focused = true;
	return (0);
}

int	on_focus_out(t_data *data)
{
	data->win_focused = false;
	mlx_mouse_move(data->mlx, data->win,
		WIN_WIDTH >> 1, WIN_HEIGHT >> 1);
	data->player.angle_mov = 0;
	return (0);
}
