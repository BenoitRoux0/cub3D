/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:40:16 by beroux            #+#    #+#             */
/*   Updated: 2023/09/16 14:37:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	parsing(argc, argv, &data);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (2);
	data.img = init_img(WIN_WIDTH, WIN_HEIGHT);
	if (!data.img)
		return (3);
	data.map_img = create_map(data.map);
	data.minimap_size = (t_vec_2i){200, 200};
	data.win_focused = true;
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, FocusOut, FocusChangeMask, on_focus_out, &data);
	mlx_hook(data.win, FocusIn, FocusChangeMask, on_focus_in, &data);
	mlx_mouse_hook(data.win, on_mouse_clic, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, on_mouvement, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_key_released, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	return (1);
}
