/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:33:43 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:01:19 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static uint32_t	my_mlx_get_pixel(void *img, int x, int y);

void	mlx_img_to_img(t_uint_img **dst, t_mlx_img *src)
{
	int	i;
	int	j;

	if (!dst || !src)
		return ;
	if (!(*dst))
		*dst = init_img(src->width, src->height);
	if (!(*dst))
		return ;
	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			(*dst)->content[i][j] = my_mlx_get_pixel(src->content, j, i);
			j++;
		}
		i++;
	}
}

static uint32_t	my_mlx_get_pixel(void *img, int x, int y)
{
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	uint32_t	color;

	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_len, &endian);
	color = *((uint32_t *)(addr + (y * line_len + x * (bits_per_pixel / 8))));
	return (color);
}
