/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:26:41 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/30 15:37:18 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	set_fps(t_fps_data *fps_data)
{
	fps_data->max_fps = FPS_TARGET;
	fps_data->fps = 0;
	fps_data->frame_count = 0;
	fps_data->fps_str = ft_strdup("First loop");
	fps_data->start = clock();
}
