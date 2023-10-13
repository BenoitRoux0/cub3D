/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:59:00 by beroux            #+#    #+#             */
/*   Updated: 2023/10/13 11:05:55 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	destroy_mlx_datas(t_data *data);

static void	destroy_imgs(t_data *data);

int	on_destroy(t_data *data)
{
	int	i;

	i = -1;
	destroy_mlx_datas(data);
	ft_free_array((void **)data->map.content);
	while (++i < 4)
	{
		if (data->map.walls_text[i] != data->fallback_wall)
			clear_img(data->map.walls_text[i]);
	}
	data->mlx = NULL;
	if (data->gamepad)
		clear_gamepads(&data->gamepad);
	destroy_imgs(data);
	if (data->sprites_list)
		clear_sprites(&data->sprites_list);
	if (data->fps_data.fps_str)
		free(data->fps_data.fps_str);
	if (data->doors_map.content)
		destroy_doors_map(data->doors_map);
	exit (0);
}

static void	destroy_imgs(t_data *data)
{
	if (data->img)
		clear_img(data->img);
	if (data->map_img)
		clear_img(data->map_img);
	clear_sprites_img(data->map.sprites, data->fallback_sprite);
	clear_weapon(data->fallback_sprite, &data->weapon);
	if (data->map.door != data->fallback_sprite)
		clear_img(data->map.door);
	clear_img(data->fallback_sprite);
	clear_img(data->fallback_wall);
}

static void	destroy_mlx_datas(t_data *data)
{
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
}
