/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/09/16 20:14:52 by gd-harco         ###   ########.fr       */
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
	if (keycode == XK_r)
	{
		data->mouse_listen = false;
		mlx_mouse_show(data->mlx, data->win);
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
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
	fill_color(data->map.colors[FLOOR], data->map.colors[CEILING]);
	update_player(data);
	render(data);
	img_to_mlx_img(data->mlx, &data->master_img, data->img);
	mlx_put_image_to_window(data->mlx,
		data->win, data->master_img->content, 0, 0);
	return (0);
}

int	on_mouse(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->mouse_listen = true;
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		mlx_mouse_hide(data->mlx, data->win);
	}
	(void)x;
	(void)y;
	return (0);
}

//Currently doesn't update player rotation even tho print the info when going into th fuctnion
int	mouse_mouvement(int x, int y, t_data *data)
{
	t_vec_2i	mouse_pos;

	printf("x: %d, y: %d\n", x, y);
	if (data->mouse_listen)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &mouse_pos.x, &mouse_pos.y);
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		data->player.angle += mouse_pos.x - WIN_WIDTH / 2;
	}
	(void)y;
	(void)x;
	return (0);
}
