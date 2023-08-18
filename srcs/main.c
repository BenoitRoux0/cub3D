/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:40:16 by beroux            #+#    #+#             */
/*   Updated: 2023/08/15 09:32:08 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_data	data;
	int		start[2];
	int		end[2];
	t_line	line;

	start[0] = 5;
	start[1] = 5;
	end[0] = 150;
	end[1] = 150;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 200, 200, "cub3D");
	if (!data.win)
		return (2);
	data.master_img.img_ptr = mlx_new_image(data.mlx, 200, 200);
	line = create_line(start, end);
	data.master_img.addr = mlx_get_data_addr(data.master_img.img_ptr,
			&data.master_img.bits_per_pixel,
			&data.master_img.line_length,
			&data.master_img.endian);
	nlx_draw_line(&data.master_img, &line, COLOR_WHITE);
	mlx_put_image_to_window(data.mlx, data.win, data.master_img.img_ptr, 0, 0);
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_loop(data.mlx);
	return (1);
}
