/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/09/29 13:56:23 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include "cub_bonus.h"

typedef struct s_gamepad	t_gamepad;

//-----------------ENUM-----------------//
enum e_dir
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
};

enum e_input_modes
{
	keyboard,
	keyboard_mouse,
	controller,
	guitar,
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

typedef struct s_angle_data
{
	double	deg;
	double	rad;
	double	angle_cos;
	double	angle_sin;
}	t_angle_data;

typedef struct s_sprite
{
	t_uint_img	*src;
	double		height;
	int			cell[2];
	double		pos[2];
}	t_sprite;

typedef struct s_map
{
	char		**content;
	t_vec_2i	size;
	t_uint_img	*walls_text[4];
	uint32_t	colors[2];
	t_sprite	sprites[88];
}	t_map;

typedef struct s_player
{
	double			pos[2];
	double			mov[2];
	double			angle_mov;
	t_angle_data	angle;
	float			fov;
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

typedef struct s_mouse_info
{
	int		x;
	int		y;
	bool	listen;
}	t_mouse_info;

typedef struct s_ray
{
	double	inter[2];
	double	dist;
	bool	hit;
}	t_ray;

typedef struct s_sprite_col
{
	t_uint_img	*src;
	int			pos;
	int			height;
}	t_sprite_col;

typedef struct s_col_buffer
{
	t_ray			ray;
	t_sprite_col	sprites[0xf];
}	t_col_buffer;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	bool			win_focused;
	t_mouse_info	mouse;
	t_master_img	*master_img;
	t_uint_img		*img;
	t_map			map;
	t_player		player;
	t_col_buffer	buffers[WIN_WIDTH];
	t_angle_data	offset_raycast;
	t_angle_data	offset_start;
	bool			show_minimap;
	t_col_buffer	col_buffer[WIN_WIDTH];
	t_uint_img		*map_img;
	t_vec_2i		minimap_size;
	t_gamepad		*gamepad;
	int				input_mode;
}	t_data;

#endif
