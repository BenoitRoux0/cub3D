/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 13:05:52 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	render_weapon(t_data *data)
{
	put_img_in_img(data->img,
		data->weapon.weapon_img[data->weapon.current_frame],
		WIN_WIDTH / 1.5, WIN_HEIGHT / 1.35);
	if (data->weapon.animation)
	{
		data->weapon.frame_since_start++;
		if (data->weapon.current_frame <= 5)
		{
			if (data->weapon.frame_since_start % 2 == 0)
				data->weapon.current_frame++;
		}
		else if (data->weapon.frame_since_start % data->weapon.frame_time == 0)
			data->weapon.current_frame++;
		if (data->weapon.current_frame == data->weapon.frame_count)
		{
			data->weapon.animation = false;
			data->weapon.current_frame = 0;
			data->weapon.frame_since_start = 0;
		}
	}
	return (0);
}
