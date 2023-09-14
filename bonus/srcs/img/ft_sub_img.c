/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:36:40 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:02:06 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_uint_img	*ft_sub_img(t_uint_img *img, int pos[2], int width, int height)
{
	t_uint_img	*sub_img;
	int			i;
	int			j;

	if (pos[0] + width > img->width || pos[1] + height > img->height)
		return (NULL);
	sub_img = init_img(width, height);
	if (!sub_img)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			sub_img->content[i][j] = img->content[i + pos[1]][j + pos[0]];
			j++;
		}
		i++;
	}
	return (sub_img);
}
