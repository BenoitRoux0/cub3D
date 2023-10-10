/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fallback_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:58:19 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/10 16:56:23 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	set_fallback_values(t_data *data)
{
	data->fallback_sprite = ft_xpm_to_img(data->mlx, FALLBACK_SPRITE);
	data->fallback_wall = ft_xpm_to_img(data->mlx, FALLBACK_WALL);
	if (!data->fallback_sprite || !data->fallback_wall)
	{
		ft_dprintf(2, ERM_FALLBACK);
		parse_error_quit(data, ERC_FALLBACK);
	}
}

void	set_fallback_sprite(t_data *data)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (!data->map.sprites[i].src)
			data->map.sprites[i].src = data->fallback_sprite;
		i++;
	}
}

void	set_fallback_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->map.walls_text[i])
			data->map.walls_text[i] = data->fallback_wall;
		i++;
	}
}
