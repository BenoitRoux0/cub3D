/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:58:20 by beroux            #+#    #+#             */
/*   Updated: 2023/10/11 23:55:48 by gd-harco         ###   ########.fr       */
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
	SO,
	WEST,
	NO,
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
	int		color;
}		t_tracker;

typedef struct s_angle_data
{
	double	deg;
	double	rad;
	double	angle_cos;
	double	angle_sin;
}	t_angle_data;

typedef struct s_weapon
{
	int			current_frame;
	int			frame_count;
	int			frame_time;
	int			frame_since_start;
	t_uint_img	*weapon_img[15];
	t_uint_img	*reticle;
	bool		animation;
}				t_weapon;

typedef struct s_sprite
{
	t_uint_img	*src;
	float		height;
	float		x_pos;
	float		y_pos;
	bool		set;
}	t_sprite;

typedef struct s_sprites_list
{
	t_sprite				*sprite;
	int						pos[2];
	double					square_dist;
	struct s_sprites_list	*next;
}	t_sprites_list;

typedef struct s_map
{
	char		**content;
	t_vec_2i	size;
	t_uint_img	*walls_text[4];
	uint32_t	colors[2];
	t_sprite	sprites[26];
	t_uint_img	*door;
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
	double	angle_diff;
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
	bool			show_fps;
	t_mouse_info	mouse;
	t_master_img	*master_img;
	t_uint_img		*img;
	t_uint_img		*fallback_wall;
	t_uint_img		*fallback_sprite;
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
	t_fps_data		fps_data;
	t_weapon		weapon;
	useconds_t		delta_time;
}					t_data;

#endif
