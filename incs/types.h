/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/10/10 16:31:41 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub.h"

//-----------------ENUM-----------------//
enum e_dir
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
};

enum e_color
{
	R,
	G,
	B
};

enum
{
	FLOOR,
	CEILING
};

//-----------------STRUCT-----------------//
typedef struct s_vec_2i
{
	int	x;
	int	y;
}	t_vec_2i;

typedef struct s_tex_tracker
{
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	int		color;
}		t_tracker;

typedef struct s_map
{
	char		**content;
	t_vec_2i	size;
	t_uint_img	*walls_text[4];
	uint32_t	colors[2];
}	t_map;

typedef struct s_player
{
	double	pos[2];
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
	bool	hit;
}	t_ray;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_master_img	*master_img;
	t_uint_img		*img;
	t_map			map;
	t_player		player;
	t_ray			rays[WIN_WIDTH];
}	t_data;

#endif
