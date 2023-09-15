/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tileset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:10:40 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:03:25 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_uint_img	***cut_tiles(t_uint_img *img, int width, int height);
static void			clear_tiles(t_uint_img ***tiles);

t_tileset	*init_tileset(t_uint_img *img, int width, int height)
{
	t_tileset	*tileset;

	if (!img)
		return (NULL);
	tileset = ft_calloc(1, sizeof(t_tileset));
	if (!tileset)
		return (clear_img(img), NULL);
	tileset->width = img->width / width;
	tileset->height = img->height / height;
	tileset->content = cut_tiles(img, width, height);
	clear_img(img);
	if (!tileset->content)
		return (clear_tileset(tileset), NULL);
	return (tileset);
}

void	clear_tileset(t_tileset *tileset)
{
	int	i;
	int	j;

	if (!tileset)
		return ;
	if (!tileset->content)
	{
		free(tileset);
		return ;
	}
	i = 0;
	while (i < tileset->height && tileset->content[i])
	{
		j = 0;
		while (j < tileset->width && tileset->content[i][j])
		{
			clear_img(tileset->content[i][j]);
			j++;
		}
		free(tileset->content[i]);
		i++;
	}
	free(tileset->content);
	free(tileset);
}

static t_uint_img	***cut_tiles(t_uint_img *img, int width, int height)
{
	int			i;
	int			j;
	int			pos[2];
	t_uint_img	***tiles;

	tiles = ft_calloc(img->height / height + 1, sizeof(t_uint_img **));
	if (!tiles)
		return (NULL);
	i = 0;
	while (i < img->height / height)
	{
		j = 0;
		tiles[i] = ft_calloc(img->width / width + 1, sizeof(t_uint_img *));
		if (!tiles[i])
			return (clear_tiles(tiles), NULL);
		while (j < img->width / width)
		{
			pos[1] = i * 32;
			pos[0] = j * 32;
			tiles[i][j] = ft_sub_img(img, pos, width, height);
			j++;
		}
		i++;
	}
	return (tiles);
}

static void	clear_tiles(t_uint_img ***tiles)
{
	int	i;
	int	j;

	i = 0;
	while (tiles[i])
	{
		j = 0;
		while (tiles[i][j])
		{
			clear_img(tiles[i][j]);
			j++;
		}
		free(tiles[i]);
		i++;
	}
	free(tiles);
}
