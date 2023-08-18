/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:39:55 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:05:32 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	rev_arr(uint32_t *arr, int size);
static void	rev_ptr_arr(uint32_t **arr, int size);

void	flip_horizontaly(t_uint_img *img)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		rev_arr(img->content[i], img->width);
		i++;
	}
}

void	flip_verticaly(t_uint_img *img)
{
	rev_ptr_arr(img->content, img->height);
}

static void	rev_arr(uint32_t *arr, int size)
{
	int			i;
	uint32_t	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
		i++;
	}
}

static void	rev_ptr_arr(uint32_t **arr, int size)
{
	int			i;
	uint32_t	*tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
		i++;
	}
}
