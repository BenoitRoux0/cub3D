/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:56:48 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:04:10 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rewrite_img(t_uint_img *img)
{
	int	i;
	int	j;

	if (!img)
		return ;
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img->content[i][j] = 0;
			j++;
		}
		i++;
	}
}
