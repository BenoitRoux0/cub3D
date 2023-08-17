/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:21:38 by gd-harco          #+#    #+#             */
/*   Updated: 2023/08/15 20:21:38 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub.h"

t_line	create_line(int start[2], int end[2]);
void	nlx_pixel_put(t_master_img	*img, int to_put[2], int color);
void	nlx_draw_line(t_master_img *img, t_line *to_draw, int color);
void	draw_straight_line(int start[2], int end[2], t_master_img *img);
void	draw_low_slope(int start[2],
			t_line params, t_master_img *img);
void	draw_high_slope(int start[2],
			t_line params, t_master_img *img);

# define COLOR_WHITE 0x00FFFFFF
# define COLOR_BLUE 0x000000FF
# define COLOR_SEA_BLUE 0x00003D60
# define COLOR_SAND 0x00C2B280
# define COLOR_LIGHT_GRASS 0x00326500
# define COLOR_MID_GRASS 0x00254C00
# define COLOR_DARK_GRASS 0x00193200
# define COLOR_ROCK 0x005A4D41
# define COLOR_SNOW_WHITE 0x00FFFAFA4

#endif
