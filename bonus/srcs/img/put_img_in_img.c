/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_in_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:30:08 by beroux            #+#    #+#             */
/*   Updated: 2023/05/18 14:19:55 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_img_in_img(t_uint_img *dst, t_uint_img *src, int x, int y)
{
	int			i;
	int			j;
	uint32_t	to_add;

	if (!dst || !src)
		return ;
	i = 0;
	if (y < 0)
		i = -y;
	while (i < src->height && i + y < dst->height)
	{
		j = 0;
		if (x < 0)
			j = -x;
		while (j < src->width && j + x < dst->width)
		{
			to_add = mix_colors(dst->content[i + y][j + x], src->content[i][j]);
			dst->content[i + y][j + x] = to_add;
			j++;
		}
		i++;
	}
}
