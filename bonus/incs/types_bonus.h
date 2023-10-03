/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/10/02 00:44:23 by beroux           ###   ########.fr       */
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

typedef struct s_tex_tracker
{
	bool	north;
	bool	south;
	bool	west;
	bool	east;
}		t_tracker;

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
	float		height;
	float		x_pos;
	float		y_pos;
}	t_sprite;

typedef struct s_sprites_list
{
	t_sprite				*sprite;
	int						pos[2];
	struct s_sprites_list	*next;
}	t_sprites_list;

typedef struct s_map
{
	char		**content;
	t_vec_2i	size;
	t_uint_img	*walls_text[4];
	uint32_t	colors[2];
	t_sprite	sprites[26];
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
	t_sprite	*src;
	int			pos;
	double		dist;
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
	t_sprites_list	*sprites_list;
	t_angle_data	offset_raycast;
	t_angle_data	offset_start;
	bool			show_minimap;
	t_uint_img		*map_img;
	int				minimap_size;
	t_gamepad		*gamepad;
	int				input_mode;
}	t_data;

#endif
