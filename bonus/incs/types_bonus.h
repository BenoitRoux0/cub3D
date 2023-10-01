/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 15:19:29 by gd-harco         ###   ########.fr       */
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

typedef struct s_map
{
	char		**content;
	t_vec_2i	size;
	t_uint_img	*walls_text[4];
	uint32_t	colors[2];
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

typedef struct s_fps_data
{
	int				fps;
	int				max_fps;
	int				frame_time_us;
	int				frame_count;
	char			*fps_str;
	int				time_left_in_frame;
	struct timeval	second_end;
	clock_t			frame_start;
	clock_t			frame_end;
}					t_fps_data;

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
	t_ray			rays[WIN_WIDTH];
	t_angle_data	offset_raycast;
	t_angle_data	offset_start;
	bool			show_minimap;
	t_uint_img		*map_img;
	int				minimap_size;
	t_gamepad		*gamepad;
	int				input_mode;
	t_fps_data		fps_data;
}	t_data;

#endif
