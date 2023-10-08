/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/10/04 16:47:49 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	on_destroy(t_data *data)
{
	int	i;

	i = -1;
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->master_img && data->mlx)
	{
		mlx_destroy_image(data->mlx, data->master_img->content);
		free(data->master_img);
	}
	data->win = NULL;
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_array((void **)data->map.content);
	while (++i < 4)
	{
		if (data->map.walls_text[i] != data->fallback_wall)
			clear_img(data->map.walls_text[i]);
	}
	data->mlx = NULL;
	if (data->img)
		clear_img(data->img);
	if (data->gamepad)
		clear_gamepads(&data->gamepad);
	if (data->map_img)
		clear_img(data->map_img);
	clear_sprites_img(data->map.sprites, data->fallback_sprite);
	clear_img(data->fallback_sprite);
	clear_img(data->fallback_wall);
	if (data->sprites_list)
		clear_sprites(&data->sprites_list);
	if (data->fps_data.fps_str)
		free(data->fps_data.fps_str);
	exit (0);
}

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == XK_Tab)
	{
		data->show_minimap = !data->show_minimap;
		render_to_window(data);
	}
	if (keycode == XK_F3)
		data->show_fps = !data->show_fps;
	if (keycode == XK_Escape)
		on_destroy(data);
	if (keycode == XK_m)
		data->input_mode++;
	data->input_mode %= 4;
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

	update_gamepads(data->gamepad);
	tmp = data->gamepad;
	while (tmp)
	{
		update_inputs(tmp);
		tmp = tmp->next;
	}
	if (data->player.mov[0] == 0 && data->player.mov[1] == 0 && \
		data->player.angle_mov == 0)
		return (0);
	if (data->mouse.listen && data->mouse.x != (WIN_WIDTH >> 1)
		&& data->win_focused)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH >> 1, WIN_HEIGHT >> 1);
	update_player(data);
	render_locked_fps(data);
	return (0);
}
