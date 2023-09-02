/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/09/01 16:12:32 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub.h"

enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum
{
	R,
	V,
	B
};

enum
{
	FLOOR,
	CEILING
};

typedef struct s_map
{
	char	**content;
	t_img	walls_text[4];
	int		colors[2][3];
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_data;

typedef struct s_player
{
	float	pos[2];
	double	angle;
	float	fov;
}	t_player;

#endif
