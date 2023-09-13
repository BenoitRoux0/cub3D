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

#include "cub.h"

static void		draw_wall_slice(int p, t_ray r, t_uint_img *d, t_uint_img *tex);
static t_ray	average_ray(t_ray *rays);

int	render(t_data *data)
{
	int		i;
	t_ray	ray;

	raycast(data);
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray = average_ray(&data->rays[i]);
		if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
			data->player.pos[0] - ray.inter[0] > 0)
			draw_wall_slice(i, ray, data->img, data->map.walls_text[WEST]);
		else if (fmod(ray.inter[0], CELL_SIZE) == 0 && \
				data->player.pos[0] - ray.inter[0] < 0)
			draw_wall_slice(i, ray, data->img, data->map.walls_text[EAST]);
		else if (fmod(ray.inter[1], CELL_SIZE) == 0 && \
				data->player.pos[1] - ray.inter[1] > 0)
			draw_wall_slice(i, ray, data->img, data->map.walls_text[NORTH]);
		else
			draw_wall_slice(i, ray, data->img, data->map.walls_text[SOUTH]);
		i++;
	}
	return (0);
}

static void	draw_wall_slice(int pos, t_ray r, t_uint_img *dst, t_uint_img *tex)
{
	int		i;
	double	src_pos;
	int		slice_height;
	int		src_x;

	if (!r.hit)
		return ;
	if (fmod(r.inter[0], CELL_SIZE) == 0)
		src_x = ((int) r.inter[1] % CELL_SIZE) % tex->width;
	else
		src_x = ((int) r.inter[0] % CELL_SIZE) % tex->width;
	if (src_x < 0)
		return ;
	slice_height = (int)(CELL_SIZE / r.dist * (WIN_HEIGHT));
	i = WIN_HEIGHT / 2 - slice_height / 2;
	src_pos = 0;
	if (i < 0)
	{
		src_pos = -i * (double) tex->height / (double) slice_height;
		i = 0;
	}
	while (src_pos < tex->height && i < WIN_HEIGHT)
	{
		dst->content[i][pos] = tex->content[(int) src_pos][src_x];
		src_pos += (double) tex->height / (double) slice_height;
		i++;
	}
}

static t_ray	average_ray(t_ray *rays)
{
	int		i;
	t_ray	ray;

	i = 0;
	ft_bzero(&ray, sizeof(t_ray));
	while (i < (1 << ANTI_ALIASING))
	{
		ray.inter[0] += rays[i].inter[0];
		ray.inter[1] += rays[i].inter[1];
		ray.dist += rays[i].dist;
		ray.hit |= rays[i].hit;
		i++;
	}
	ray.inter[0] /= (1 << ANTI_ALIASING);
	ray.inter[1] /= (1 << ANTI_ALIASING);
	ray.dist /= (1 << ANTI_ALIASING);
	return (ray);
}
