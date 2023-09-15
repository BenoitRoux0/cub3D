/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/09/14 19:29:03 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	if (keycode == XK_Escape)
		on_destroy(data);
	key_press_player(keycode, data);
	return (0);
}

int	on_key_released(int keycode, t_data *data)
{
	key_released_player(keycode, data);
	if (keycode == XK_Tab)
		data->show_minimap = !data->show_minimap;
	return (0);
}

int	on_loop(t_data *data)
{
	t_uint_img	*minimap;

	rewrite_img(data->img);
	update_player(data);
	render(data);
	if (data->show_minimap)
	{
		printf("show minimap\n");
		minimap = cut_minimap(data);
		put_img_in_img(data->img, minimap, 0, 0);
		clear_img(minimap);
	}
	img_to_mlx_img(data->mlx, &data->master_img, data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->master_img->content, 0, 0);
	return (0);
}
