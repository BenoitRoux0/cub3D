/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_mlx_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:33:43 by beroux            #+#    #+#             */
/*   Updated: 2023/05/24 11:38:13 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void			my_mlx_pixel_put(t_master_img *data, int x, int y, uint32_t c);
static t_master_img	*new_mlx_img(void *mlx, int width, int heigth);

void	img_to_mlx_img(void *mlx, t_master_img **dst, t_uint_img *src)
{
	int	i;
	int	j;

	if (!dst || !src)
		return ;
	if (!(*dst))
	{
		*dst = new_mlx_img(mlx, src->width, src->height);
		if (!(*dst))
			return ;
	}
	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			my_mlx_pixel_put(*dst, j, i, src->content[i][j]);
			j++;
		}
		i++;
	}
}

static void	my_mlx_pixel_put(t_master_img *img, int x, int y, uint32_t c)
{
	char	*addr;

	addr = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(uint32_t *) addr = c;
}

static t_master_img	*new_mlx_img(void *mlx, int width, int heigth)
{
	t_master_img	*img;

	img = ft_calloc(1, sizeof(t_master_img));
	if (!img)
		return (NULL);
	img->content = mlx_new_image(mlx, width, heigth);
	if (!img->content)
		return (free(img), NULL);
	img->width = width;
	img->height = heigth;
	img->addr = mlx_get_data_addr(\
				img->content, \
				&(img->bits_per_pixel), \
				&(img->line_len), \
				&(img->endian));
	return (img);
}
