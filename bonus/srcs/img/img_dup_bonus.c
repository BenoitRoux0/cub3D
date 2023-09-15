/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:48:31 by beroux            #+#    #+#             */
/*   Updated: 2023/08/15 23:48:31 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:22:17 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:05:04 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_uint_img	*img_dup(t_uint_img *src)
{
	t_uint_img	*img;
	int			i;
	int			j;

	if (!src)
		return (NULL);
	img = init_img(src->width, src->height);
	if (!img)
		return (NULL);
	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			img->content[i][j] = src->content[i][j];
			j++;
		}
		i++;
	}
	return (img);
}
