/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:40:16 by beroux            #+#    #+#             */
/*   Updated: 2023/08/29 18:06:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "img.h"

static int	draw_map(t_map map, t_uint_img *dst);
static int	draw_player(t_player *player, t_uint_img *dst);
static int	loop_hook(t_data *data);

int	main(void)
{
	t_data	data;
	const char *map[] = {
			"11111111111",
			"10000100001",
			"10000000001",
			"10000000001",
			"11111111111"
	};

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 200, 200, "cub3D");
	if (!data.win)
		return (2);
	data.map.content = (char **) map;
	data.map.size[0] = 11;
	data.map.size[1] = 5;
	data.player = init_player(NORTH, (int[2]) {3, 3});
	mlx_do_key_autorepeatoff(data.mlx);
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_destroy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_key_released, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	return (1);
}

int	loop_hook(t_data *data)
{
	t_uint_img			*dst;
	static t_master_img	*to_put = NULL;
	int					i;

	update_player(data);
	raycast(data);
	dst = init_img(WIN_WIDTH, WIN_HEIGHT);
	draw_map(data->map, dst);
	draw_player(&data->player, dst);
	i = 0;
	while (i < WIN_WIDTH)
	{
		if (data->rays[i].inter[0] < WIN_WIDTH && data->rays[i].inter[1] < WIN_HEIGHT && data->rays[i].inter[0] > 0 && data->rays[i].inter[1] > 0)
		{
			dst->content[(int) data->rays[i].inter[1]][(int) data->rays[i].inter[0]] = color_to_uint32_t((t_color) {255, 0, 255, 0});
		}
		i++;
	}
	img_to_mlx_img(data->mlx, &to_put, dst);
	mlx_put_image_to_window(data->mlx, data->win, to_put->content, 0, 0);
	clear_img(dst);
	return (0);
}

int draw_map(t_map map, t_uint_img *dst)
{
	int	i;
	int	j;

	i = 0;
	while (i < dst->height && i < map.size[1] * CELL_SIZE)
	{
		j = 0;
		while (j < dst->width && j < map.size[0] * CELL_SIZE)
		{
			dst->content[i][j] = color_to_uint32_t((t_color) {255, 0, 0, 0});
			if (map.content[i / CELL_SIZE][j / CELL_SIZE] == '1')
				dst->content[i][j] = color_to_uint32_t((t_color) {255, 255, 255, 255});
			j++;
		}
		i++;
	}
	return (0);
}

int draw_player(t_player *player, t_uint_img *dst)
{
	int	i;
	int	j;

	i = 0;
	while (i < dst->height)
	{
		j = 0;
		while (j < dst->width)
		{
			if (pow(player->pos[0] - j, 2) + pow(player->pos[1] - i, 2) <= 25)
				dst->content[i][j] = color_to_uint32_t((t_color) {255, 255, 0, 0});
			j++;
		}
		i++;
	}
	return (0);
}

