/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/09/19 17:11:25 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	on_destroy(t_data *data)
{
	int	i;

	i = -1;
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_array((void **)data->map.content);
	while (++i < 4)
		clear_img(data->map.walls_text[i]);
	data->mlx = NULL;
	exit (0);
}

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == XK_Tab)
	{
		data->show_minimap = !data->show_minimap;
		render_to_window(data);
	}
	if (keycode == XK_Escape)
		on_destroy(data);
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
	if (data->player.mov[0] == 0 && data->player.mov[1] == 0 && \
		data->player.angle_mov == 0)
		return (0);
	if (data->mouse.listen && data->mouse.x != WIN_WIDTH / 2
		&& data->win_focused)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	update_player(data);
	render_to_window(data);
	return (0);
}
