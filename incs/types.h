/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/08/15 09:10:39 by beroux           ###   ########.fr       */
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

typedef struct s_map
{
	char	**content;
	t_img	walls_text[4];
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