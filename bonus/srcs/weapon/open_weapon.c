/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_weapon_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:55:14 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 11:18:34 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	fill_table(char *path[15]);
static void	check_for_null(t_weapon *weapon, t_uint_img *fallback_sprite);

void open_weapon_sprites(t_data *data)
{
	char	*path[15];
	int		i;

	fill_table(path);
	i = -1;
	while (++i < 15)
		data->weapon.weapon_img[i] = ft_xpm_to_img(data->mlx, path[i]);
	check_for_null(&data->weapon, data->fallback_sprite);
	data->weapon.frame_count = 14;
}

void	fill_table(char *path[15])
{
	path[0] = "./textures/weapon/01.xpm";
	path[1] = "./textures/weapon/02.xpm";
	path[2] = "./textures/weapon/03.xpm";
	path[3] = "./textures/weapon/04.xpm";
	path[4] = "./textures/weapon/05.xpm";
	path[5] = "./textures/weapon/06.xpm";
	path[6] = "./textures/weapon/07.xpm";
	path[7] = "./textures/weapon/08.xpm";
	path[8] = "./textures/weapon/09.xpm";
	path[9] = "./textures/weapon/10.xpm";
	path[10] = "./textures/weapon/11.xpm";
	path[11] = "./textures/weapon/12.xpm";
	path[12] = "./textures/weapon/13.xpm";
	path[13] = "./textures/weapon/14.xpm";
	path[14] = "./textures/weapon/15.xpm";
}

static void	check_for_null(t_weapon *weapon, t_uint_img *fallback_sprite)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		if (!weapon->weapon_img[i])
			weapon->weapon_img[i] = fallback_sprite;
	}
}
