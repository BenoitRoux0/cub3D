/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:26:41 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/30 17:31:38 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	set_fps(t_fps_data *fps_data)
{
	fps_data->max_fps = FPS;
	fps_data->fps = 0;
	fps_data->frame_count = 0;
	fps_data->fps_str = ft_strdup("First loop");
	fps_data->frame_time_us = 1000000 / FPS;
}

int	time_difference(clock_t start, clock_t end)
{
	int	start_in_us;
	int	end_in_us;

	start_in_us = start * 1000000 / CLOCKS_PER_SEC;
	end_in_us = end * 1000000 / CLOCKS_PER_SEC;
	return (end_in_us - start_in_us);
}

void	render_locked_fps(t_data *data)
{
	int	elapsed_time;
	int	time_left_in_frame;

	data->fps_data.frame_start = clock();
	render_to_window(data);
	if (((clock() - data->fps_data.second_check) / CLOCKS_PER_SEC) >= 1)
	{
		free(data->fps_data.fps_str);
		data->fps_data.fps_str = ft_itoa(data->fps_data.frame_count);
		data->fps_data.frame_count = 0;
		data->fps_data.second_check = clock();
	}
	data->fps_data.frame_end = clock();
	elapsed_time = time_difference(data->fps_data.frame_start,
		data->fps_data.frame_end);
	data->fps_data.frame_end = clock();
	time_left_in_frame = data->fps_data.frame_time_us - elapsed_time;
	if (time_left_in_frame > 0)
		usleep(time_left_in_frame);
}
