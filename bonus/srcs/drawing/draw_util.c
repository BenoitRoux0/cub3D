/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlx_draw_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:22:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/04/28 18:13:18 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file nlx_draw_util.c
 *
 * @brief supplementary file containing every function related to draws in nlx
 *
 * @author gd-harco
 * @date 2023-04-03
 * @version 1.2
 */
#include "cub.h"

/**
 * @brief Draw a straight line on an image
 * @details The function check if the line is vertical or horizontal and draw it.
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 * @return nothing
 */
void	draw_straight_line(int start[2], int end[2], t_master_img *img)
{
	if (start[0] == end[0])
	{
		if (start[1] > end[1])
			return (draw_straight_line(end, start, img));
		while (start[1] <= end[1])
		{
			nlx_pixel_put(img, start, COLOR_WHITE);
			start[1]++;
		}
	}
	else
	{
		if (start[0] > end[0])
			return (draw_straight_line(end, start, img));
		while (start[0] <= end[0])
		{
			nlx_pixel_put(img, start, COLOR_WHITE);
			start[0]++;
		}
	}
}

/**
 * @brief Draw a line on an image
 * @details The function will create a line from two points in a slow slope
 * using Bresenham's algorithm
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 */
void	draw_low_slope(int start[2],
				t_line params, t_master_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_x)
	{
		nlx_pixel_put(img, start, COLOR_WHITE);
		start[0] += params.x_incr;
		params.error_x -= params.diff_y;
		if (params.error_x < 0)
		{
			start[1] += params.y_incr;
			params.error_x += params.diff_x;
		}
	}
}

/**
 * @brief Draw a line on an image
 * @details The function will create a line from two points in a high slope
 * using Bresenham's algorithm
 * @param start the starting point of the line
 * @param params the parameters of the line
 * @param img the image on which the line will be drawn
 */
void	draw_high_slope(int start[2],
				t_line params, t_master_img *img)
{
	int	i;

	i = -1;
	while (++i <= params.starting_error_y && start[1] > 0)
	{
		nlx_pixel_put(img, start, COLOR_WHITE);
		start[1] += params.y_incr;
		params.error_y -= params.diff_x;
		if (params.error_y < 0)
		{
			start[0] += params.x_incr;
			params.error_y += params.diff_y;
		}
	}
}
