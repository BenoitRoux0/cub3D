/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/09/19 16:58:13 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		clear_img(data->map.walls_text[i]);
	data->mlx = NULL;
	if (data->img)
		clear_img(data->img);
	exit (0);
}

int	on_key_press(int keycode, t_data *data)
{
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
	fill_color(data->img, data->map.colors[FLOOR], data->map.colors[CEILING]);
	update_player(data);
	render(data);
	img_to_mlx_img(data->mlx, &data->master_img, data->img);
	mlx_put_image_to_window(data->mlx, data->win,
		data->master_img->content, 0, 0);
	return (0);
}
