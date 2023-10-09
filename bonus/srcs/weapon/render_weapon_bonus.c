/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:39:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 12:49:43 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	render_weapon(t_data *data)
{
	put_img_in_img(data->img,
		data->weapon.weapon_img[data->weapon.current_frame],
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (data->weapon.animation)
	{
		data->weapon.current_frame++;
		if (data->weapon.current_frame == data->weapon.frame_count)
		{
			data->weapon.animation = false;
			data->weapon.current_frame = 0;
		}
	}
	return (0);
}
