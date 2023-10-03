/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:40:16 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 04:15:54 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "cub_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	parsing(argc, argv, &data);
	data.gamepad = init_gamepads(1);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (2);
	data.img = init_img(WIN_WIDTH, WIN_HEIGHT);
	if (!data.img)
		return (3);
	data.map_img = create_map(data.map);
	data.minimap_size = WIN_HEIGHT / 7;
	data.win_focused = true;
	init_angles(&data);
	render_to_window(&data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, FocusOut, FocusChangeMask, on_focus_out, &data);
	mlx_hook(data.win, FocusIn, FocusChangeMask, on_focus_in, &data);
	mlx_mouse_hook(data.win, on_mouse_clic, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, on_mouvement, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_key_released, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	button_pressed_hook(data.gamepad, js_button_press_player, 0, &data);
	button_released_hook(data.gamepad, js_button_released_player, 0, &data);
	axis_hook(data.gamepad, js_joystick_moved_player, 0, &data);
	mlx_loop(data.mlx);
	return (1);
}
