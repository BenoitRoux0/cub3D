/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_player_js.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:42:27 by beroux            #+#    #+#             */
/*   Updated: 2023/10/09 17:03:23 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	gamepad_moves(int key_code, int16_t value, t_data *data);

int	js_button_press_player(int key_code, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	if (data->input_mode != controller && data->input_mode != guitar)
		return (0);
	if (key_code == button_start)
		data->show_minimap = !data->show_minimap;
	if (data->input_mode != guitar)
		return (0);
	if (key_code == button_B)
		data->player.mov[0] += 1;
	if (key_code == button_Y)
		data->player.mov[0] -= 1;
	if (key_code == button_A)
		data->player.angle_mov -= 1;
	if (key_code == button_X)
		data->player.angle_mov += 1;
	if (key_code == LB)
		data->weapon.animation = true;
	printf("keycode: %d %d\n", key_code, LB);
	return (0);
}

int	js_button_released_player(int key_code, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	if (data->input_mode != guitar)
		return (0);
	if (key_code == button_B)
		data->player.mov[0] -= 1;
	if (key_code == button_Y)
		data->player.mov[0] += 1;
	if (key_code == button_A)
		data->player.angle_mov += 1;
	if (key_code == button_X)
		data->player.angle_mov -= 1;
	return (0);
}

int	js_joystick_moved_player(int key_code, int16_t value, void *data_ptr)
{
	t_data	*data;

	data = data_ptr;
	if (data->input_mode != guitar && data->input_mode != controller)
		return (0);
	if (key_code == string && value > 0)
		data->player.mov[1] = 1;
	if (key_code == string && value == 0)
		data->player.mov[1] = 0;
	if (key_code == string && value < 0)
		data->player.mov[1] = -1;
	if (data->input_mode != controller)
		return (0);
	gamepad_moves(key_code, value, data);
	if (key_code == RT && value > 32000)
		data->weapon.animation = true;
	return (0);
}

static void	gamepad_moves(int key_code, int16_t value, t_data *data)
{
	if (key_code == R_js_X && abs(value) > 8000)
		data->player.angle_mov = value * 0.000045;
	else if (key_code == R_js_X)
		data->player.angle_mov = 0;
	if (key_code == L_js_X && abs(value) > 8000)
		data->player.mov[0] = -value * 0.000045;
	else if (key_code == L_js_X)
		data->player.mov[0] = 0;
	if (key_code == L_js_Y && abs(value) > 8000)
		data->player.mov[1] = -value * 0.000045;
	else if (key_code == L_js_Y)
		data->player.mov[1] = 0;
}
