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

typedef struct s_master_img	t_master_img;

typedef struct s_map
{
	char	**content;
	t_img	walls_text[4];
}	t_map;

typedef struct s_player
{
	float	pos[2];
	double	angle;
	float	fov;
}	t_player;

typedef struct s_line
{
	int		start[2];
	int		end[2];
	int		error_x;
	int		error_y;
	int		diff_x;
	int		diff_y;
	int		starting_error_x;
	int		starting_error_y;
	int		x_incr;
	int		y_incr;
}				t_line;

struct s_master_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_master_img	master_img;
	t_map			map;
}	t_data;
#endif
