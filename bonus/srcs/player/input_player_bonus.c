/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:06:05 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 18:03:54 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	key_press_player(int key_code, t_data *data)
{
	if (data->input_mode != keyboard && data->input_mode != keyboard_mouse)
		return (0);
	if (key_code == XK_e)
		player_interact(data);
	if (key_code == XK_w)
		data->player.mov[1] += 1;
	if (key_code == XK_s)
		data->player.mov[1] -= 1;
	if (key_code == XK_a)
		data->player.mov[0] += 1;
	if (key_code == XK_d)
		data->player.mov[0] -= 1;
	if (data->input_mode != keyboard)
		return (0);
	if (key_code == XK_Left)
		data->player.angle_mov -= 1;
	if (key_code == XK_Right)
		data->player.angle_mov += 1;
	return (0);
}

int	key_released_player(int key_code, t_data *data)
{
	if (data->input_mode != keyboard && data->input_mode != keyboard_mouse)
		return (0);
	if (key_code == XK_w)
		data->player.mov[1] -= 1;
	if (key_code == XK_s)
		data->player.mov[1] += 1;
	if (key_code == XK_a)
		data->player.mov[0] -= 1;
	if (key_code == XK_d)
		data->player.mov[0] += 1;
	if (data->input_mode != keyboard && data->input_mode != keyboard_mouse)
		return (0);
	if (key_code == XK_Left)
		data->player.angle_mov += 1;
	if (key_code == XK_Right)
		data->player.angle_mov -= 1;
	return (0);
}
