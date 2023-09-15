/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:20 by beroux            #+#    #+#             */
/*   Updated: 2023/09/13 00:35:27 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void		draw_wall_slice(t_data *data,int p, t_ray r, t_uint_img *tex);
static void		draw_color_column(t_uint_img *dst, int pos, int start, int end, uint32_t color);

int	render(t_data *data)
{
	int		i;
	t_ray	ray;

	raycast(data);
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray = data->rays[i];
		if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
			data->player.pos[0] - ray.inter[0] > 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[WEST]);
		else if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
				data->player.pos[0] - ray.inter[0] < 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[EAST]);
		else if (fmod(ray.inter[1], CELL_SIZE) == 0 && \
				data->player.pos[1] - ray.inter[1] > 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[NORTH]);
		else
			draw_wall_slice(data, i, ray, data->map.walls_text[SOUTH]);
		i++;
	}
	return (0);
}

static void	draw_wall_slice(t_data *data, int pos, t_ray r, t_uint_img *tex)
{
	int		i;
	double	src_pos;
	int		slice_height;
	int		src_x;

	src_x = ((int) r.inter[0] % CELL_SIZE) % tex->width;
	if (fmod(r.inter[0], CELL_SIZE) == 0)
		src_x = ((int) r.inter[1] % CELL_SIZE) % tex->width;
	if (src_x < 0 || !r.hit)
		return (draw_color_column(data->img, pos, 0, WIN_HEIGHT / 2, data->map.colors[CEILING]), draw_color_column(data->img, pos, WIN_HEIGHT / 2, WIN_HEIGHT, data->map.colors[FLOOR]));
	slice_height = (int)(CELL_SIZE / r.dist * (WIN_HEIGHT));
	i = WIN_HEIGHT / 2 - slice_height / 2;
	src_pos = 0;
	if (i < 0)
	{
		src_pos = -i * (double) tex->height / (double) slice_height;
		i = 0;
	}
	draw_color_column(data->img, pos, 0, i, data->map.colors[CEILING]);
	while (src_pos < tex->height && i < WIN_HEIGHT)
	{
		data->img->content[i][pos] = tex->content[(int) src_pos][src_x];
		src_pos += (double) tex->height / (double) slice_height;
		i++;
	}
	draw_color_column(data->img, pos, i, WIN_HEIGHT, data->map.colors[FLOOR]);
}

static void		draw_color_column(t_uint_img *dst, int pos, int start, int end, uint32_t color)
{
	int	i;

	i = start;
	if (end < start)
	{
		i = end;
		end = start;
	}
	while (i < end)
	{
		dst->content[i][pos] = color;
		i++;
	}
}
