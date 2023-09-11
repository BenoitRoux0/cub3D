/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:20:53 by beroux            #+#    #+#             */
/*   Updated: 2023/09/11 17:01:58 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_map(t_data *data);
static void	draw_player(t_data *data);

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
	return (0);
}

int	on_loop(t_data *data)
{
	static t_master_img	*img = NULL;

	rewrite_img(data->img);
	update_player(data);
	render(data);
	draw_map(data);
	draw_player(data);
	img_to_mlx_img(data->mlx, &img, data->img);
	mlx_put_image_to_window(data->mlx, data->win, img->content, 0, 0);
	return (0);
}

static void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i / 16 < data->map.size.y && j / 16 < data->map.size.x && data->map.content[i / 16][j / 16] == '1')
				data->img->content[i][j] = color_to_uint32_t((t_color) {255, 0, 0, 255});
			j++;
		}
		i++;
	}
}

static void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (pow(i - data->player.pos[1] / 4, 2) + pow(j - data->player.pos[0] / 4, 2) < 25)
				data->img->content[i][j] = color_to_uint32_t((t_color) {255, 255, 0, 0});
			j++;
		}
		i++;
	}
}
