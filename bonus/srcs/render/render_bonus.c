/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:20 by beroux            #+#    #+#             */
/*   Updated: 2023/10/09 14:40:27 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	draw_wall_slice(t_data *data, int p, t_ray r, t_uint_img *tex);

static void	update_sprites(t_data *data);

int	render(t_data *data)
{
	int		i;
	t_ray	ray;

	raycast(data);
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray = data->buffers[i].ray;
		if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
			data->player.pos[0] - ray.inter[0] > 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[WEST]);
		else if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
				data->player.pos[0] - ray.inter[0] < 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[EAST]);
		else if (fmod(ray.inter[1], CELL_SIZE) == 0 && \
				data->player.pos[1] - ray.inter[1] > 0)
			draw_wall_slice(data, i, ray, data->map.walls_text[NO]);
		else
			draw_wall_slice(data, i, ray, data->map.walls_text[SO]);
		i++;
	}
	update_sprites(data);
	return (0);
}

static void	update_sprites(t_data *data)
{
	fill_sprites_buffers(data);
	draw_sprites(data);
	clear_sprites(&data->sprites_list);
	ft_bzero(&data->buffers, sizeof (t_col_buffer) * WIN_WIDTH);
}

static void	draw_wall_slice(t_data *data, int pos, t_ray r, t_uint_img *tex)
{
	int		i;
	double	src_pos;
	int		slice_height;
	int		src_x;

	r.dist *= cos(r.angle_diff * M_PI_4 / 45);
	src_x = ((int) r.inter[0] % CELL_SIZE) * tex->width >> CELL_SH;
	if (fmod(r.inter[0], CELL_SIZE) == 0)
		src_x = ((int) r.inter[1] % CELL_SIZE) * tex->width >> CELL_SH;
	if (src_x < 0 || !r.hit)
		return ;
	slice_height = (int)(CELL_SIZE / r.dist * (WIN_HEIGHT));
	i = (WIN_HEIGHT >> 1) - (slice_height >> 1);
	src_pos = 0;
	if (i < 0)
	{
		src_pos = -i * (double) tex->height / (double) slice_height;
		i = 0;
	}
	while (src_pos < tex->height && i < WIN_HEIGHT)
	{
		data->img->content[i][pos] = tex->content[(int) src_pos][src_x];
		src_pos += (double) tex->height / (double) slice_height;
		i++;
	}
}

int	fill_color(t_uint_img *dst, uint32_t floor, uint32_t ceiling)
{
	t_vec_2i	pos;

	pos.y = 0;
	while (pos.y < (WIN_HEIGHT >> 1))
	{
		pos.x = 0;
		while (pos.x < WIN_WIDTH)
		{
			dst->content[pos.y][pos.x] = ceiling;
			pos.x++;
		}
		pos.y++;
	}
	while (pos.y < WIN_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WIN_WIDTH)
		{
			dst->content[pos.y][pos.x] = floor;
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int	render_to_window(t_data *data)
{
	fill_color(data->img, data->map.colors[FLOOR], data->map.colors[CEILING]);
	render(data);
	if (data->show_minimap)
		minimap_draw(data);
	render_weapon(data);
	img_to_mlx_img(data->mlx, &data->master_img, data->img);
	mlx_put_image_to_window(data->mlx, data->win,
		data->master_img->content, 0, 0);
	if (data->show_fps)
		mlx_string_put(data->mlx, data->win, WIN_WIDTH - 20, WIN_HEIGHT >> 1,
			FPS_COLOR_GREEN, data->fps_data.fps_str);
	data->fps_data.frame_count++;
	return (0);
}
