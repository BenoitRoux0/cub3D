/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_second.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:40:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/30 16:26:36 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_SECOND_BONUS_H
# define FRAME_SECOND_BONUS_H

# include "cub_bonus.h"

void	set_fps(t_fps_data *fps_data);
void	render_locked_fps(t_data *data);


# define FPS_COLOR_GREEN 0x00FF00
# define FPS_COLOR_RED 0xFF0000
#endif
