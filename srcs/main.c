/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:40:16 by beroux            #+#    #+#             */
/*   Updated: 2023/09/02 14:50:06 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		parsing_result;

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	parsing_result = parsing(argc, argv, &data);
	if (parsing_result != 0)
		return (free(data.mlx), parsing_result);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (2);
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_key_released, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	return (1);
}
