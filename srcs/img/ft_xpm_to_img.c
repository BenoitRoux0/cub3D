/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 04:32:14 by beroux            #+#    #+#             */
/*   Updated: 2023/09/03 04:39:40 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:08:37 by beroux            #+#    #+#             */
/*   Updated: 2023/05/24 12:48:22 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_uint_img	ft_xpm_to_img(void *mlx_ptr, char *path)
{
	t_uint_img	*img;
	t_uint_img	res;
	t_mlx_img	*mlx_img;
	int			*width_p;
	int			*height_p;

	mlx_img = ft_calloc(1, sizeof(t_mlx_img));
	img = NULL;
	if (!mlx_img)
		return ((t_uint_img) {NULL, 0, 0});
	width_p = &(mlx_img->width);
	height_p = &(mlx_img->height);
	mlx_img->content = mlx_xpm_file_to_image(mlx_ptr, path, width_p, height_p);
	if (!mlx_img->content)
		return (free(mlx_img), (t_uint_img) {NULL, 0, 0});
	mlx_img_to_img(&img, mlx_img);
	mlx_destroy_image(mlx_ptr, mlx_img->content);
	free(mlx_img);
	res = *img;
	free(img);
	return (res);
}
