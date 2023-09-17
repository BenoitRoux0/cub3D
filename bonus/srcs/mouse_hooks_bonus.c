/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:15:59 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/17 12:15:59 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	on_mouse_clic(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->mouse.listen = true;
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		mlx_mouse_hide(data->mlx, data->win);
	}
	if (button == 2)
	{
		data->mouse.listen = false;
		mlx_mouse_show(data->mlx, data->win);
	}
	(void)x;
	(void)y;
	return (0);
}

int	on_mouvement(int x, int y, t_data *data)
{
	if (data->mouse.listen)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &data->mouse.x, &data->mouse.y);
		data->player.angle += (data->mouse.x - WIN_WIDTH / 2) * 0.05;
	}
	(void)y;
	(void)x;
	return (0);
}
