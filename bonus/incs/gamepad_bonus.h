/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamepad.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:37:30 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 07:46:58 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPAD_BONUS_H
# define GAMEPAD_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdint.h>
# include <errno.h>
# include <linux/joystick.h>
# include <stdbool.h>
# include "libft.h"

# define C_DEV_DIR "/dev/input/"

enum e_buttons
{
	button_A,
	button_B,
	button_X,
	button_Y,
	LB,
	RB,
	back,
	button_start,
	home,
	LS,
	RS,
	dpad_left,
	dpad_right,
	dpad_up,
	dpad_down
};

enum e_axis
{
	L_js_X,
	L_js_Y,
	LT,
	R_js_X,
	R_js_Y,
	RT,
	string = 7
};

enum e_button_hooks
{
	button_pressed,
	button_released
};

typedef int	(*t_button_func)(int, void *);
typedef int	(*t_axis_func)(int, int16_t, void *);

typedef struct s_gamepad
{
	int					fd;
	char				*name;
	ino_t				inode;
	bool				connected;
	t_button_func		button_hooks[2];
	void				*button_params[2];
	t_axis_func			axis_hook;
	void				*axis_param;
	struct s_gamepad	*next;
}	t_gamepad;

t_gamepad	*init_gamepads(int nb_gamepads);
void		clear_gamepads(t_gamepad **gamepads);
int			update_gamepads(t_gamepad *gamepads);
int			input_loop(t_gamepad *gamepad);
int			update_inputs(t_gamepad *gamepad);

void		button_pressed_hook(t_gamepad *gamepad, t_button_func func, \
								int js_number, void *data);
void		button_released_hook(t_gamepad *gamepad, t_button_func func, \
								int js_number, void *data);
void		axis_hook(t_gamepad *gamepad, t_axis_func func, \
								int js_number, void *data);

#endif
