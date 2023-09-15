/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:27:57 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 01:08:11 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_uint_img	*ft_sub_img(t_uint_img *img, int pos[2], int width, int height)
{
	t_uint_img	*sub_img;
	int			i;
	int			j;

	if (width > img->width)
		width = img->width;
	if (height > img->height)
		height = img->height;
	if (pos[0] < 0)
		pos[0] = 0;
	if (pos[1] < 0)
		pos[1] = 0;
	if (pos[0] + width > img->width)
		pos[0] = img->width - width;
	if (pos[1] + height > img->height)
		pos[1] = img->height - height;
	printf("extract img at %d %d\n", pos[0], pos[1]);
	sub_img = init_img(width, height);
	if (!sub_img)
		return (NULL);
	i = 0;
	while (i < sub_img->height && i + pos[1] < img->height)
	{
		j = 0;
		while (j < sub_img->width && j + pos[0] < img->width)
		{
			sub_img->content[i][j] = img->content[i + pos[1]][j + pos[0]];
			j++;
		}
		i++;
	}
	return (sub_img);
}
