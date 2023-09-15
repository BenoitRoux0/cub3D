/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:27:57 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 15:45:07 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_uint_img	*ft_sub_img(t_uint_img *img, int pos[2], int width, int height)
{
	t_uint_img	*sub_img;
	int			i;
	int			j;

	sub_img = init_img(width, height);
	if (!sub_img)
		return (NULL);
	i = 0;
	while (i < sub_img->height)
	{
		j = 0;
		while (j < sub_img->width)
		{
			if (i + pos[1] < 0 || j + pos[0] < 0 || \
				i + pos[1] >= img->height || j + pos[0] >= img->width)
				sub_img->content[i][j] = 0;
			else
				sub_img->content[i][j] = img->content[i + pos[1]][j + pos[0]];
			j++;
		}
		i++;
	}
	return (sub_img);
}
