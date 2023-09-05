/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:20 by beroux            #+#    #+#             */
/*   Updated: 2023/09/04 21:31:09 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_wall_slice(int pos, t_ray ray, t_uint_img *dst);

int	render(t_data *data)
{
	int	i;

	raycast(data);
	i = 0;
	while (i < WIN_WIDTH)
	{
		draw_wall_slice(i, data->rays[i], data->img);
		i++;
	}
	return (0);
}

static void	draw_wall_slice(int pos, t_ray ray, t_uint_img *dst)
{
	int	i;
	int	slice_height;

	slice_height = (int)(64 * 2.5 / ray.dist * (300));
	i = WIN_HEIGHT / 2 - slice_height / 2;
	if (i < 0)
		i = 0;
	while (i < slice_height && i < WIN_HEIGHT)
	{
		dst->content[i][pos] = color_to_uint32_t((t_color) {255, 255, 255, 255});
		i++;
	}
}