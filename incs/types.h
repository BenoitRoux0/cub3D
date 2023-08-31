/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/08/30 19:16:27 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub.h"

enum e_dir
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
};

typedef struct s_master_img	t_master_img;

typedef struct s_map
{
	char		**content;
	int			size[2];
	t_uint_img	walls_text[4];
}	t_map;

typedef struct s_player
{
	double 	pos[2];
	double	mov[2];
	double	angle_mov;
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
	void	*content;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
};

typedef struct s_ray
{
	double	inter[2];
	double	dist;
	int		hit;
}	t_ray;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_master_img	master_img;
	t_map			map;
	t_player		player;
	t_ray			rays[WIN_WIDTH];
}	t_data;

#endif
