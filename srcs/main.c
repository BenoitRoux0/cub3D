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

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	parsing(argc, argv, &data);
	data.win = mlx_new_window(data.mlx, 200, 200, "cub3D");
	if (!data.win)
		return (2);
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_loop(data.mlx);
	return (1);
}
