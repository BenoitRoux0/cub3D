/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:35:48 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/04 16:37:10 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:38:59 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:00:38 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_uint_img	*init_img(int width, int height)
{
	t_uint_img	*img;
	int			i;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = width;
	img->height = height;
	img->content = ft_calloc(height, sizeof(u_int32_t *));
	if (!img->content)
		return (clear_img(img), NULL);
	i = 0;
	while (i < height)
	{
		img->content[i] = ft_calloc(width, sizeof(uint32_t));
		if (!img->content[i])
			return (clear_img(img), NULL);
		i++;
	}
	return (img);
}

void	clear_img(t_uint_img *img)
{
	int	i;

	if (!img)
		return ;
	if (!img->content)
	{
		free(img);
		return ;
	}
	i = 0;
	while (i < img->height && img->content[i])
	{
		free(img->content[i]);
		i++;
	}
	free(img->content);
	free(img);
}

void	clear_mlx_img(void *mlx_ptr, t_mlx_img *img)
{
	if (!img)
		return ;
	if (img->content)
		mlx_destroy_image(mlx_ptr, img->content);
	free(img);
}
