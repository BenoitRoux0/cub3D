/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 13:38:20 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == XK_Tab)
		data->show_minimap = !data->show_minimap;
	if (keycode == XK_F3)
		data->show_fps = !data->show_fps;
	if (keycode == XK_space && data->input_mode == keyboard)
		data->weapon.animation = true;
	if (keycode == XK_Escape)
		on_destroy(data);
	if (keycode == XK_m)
	{
		data->input_mode++;
		data->input_mode %= 4;
		if (data->input_mode == keyboard_mouse)
		{
			mlx_mouse_hide(data->mlx, data->win);
			mlx_mouse_move(data->mlx, data->win,
				WIN_WIDTH >> 1, WIN_HEIGHT >> 1);
		}
		else
			mlx_mouse_show(data->mlx, data->win);
	}
	key_press_player(keycode, data);
	return (0);
}

int	on_key_released(int keycode, t_data *data)
{
	key_released_player(keycode, data);
	return (0);
}

int	on_loop(t_data *data)
{
	t_gamepad	*tmp;

	tmp = data->gamepad;
	while (tmp)
	{
		read_inputs(tmp);
		tmp = tmp->next;
	}
	if (data->input_mode == keyboard_mouse && data->mouse.x != (WIN_WIDTH >> 1)
		&& data->win_focused)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH >> 1, WIN_HEIGHT >> 1);
	update_player(data);
	render_locked_fps(data);
	return (0);
}
