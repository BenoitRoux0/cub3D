/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:23:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/08/15 17:23:30 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	fill_line_infos(t_line *line);

t_line	create_line(int start[2], int end[2])
{
	t_line	line;

	line.start[0] = start[0] + 0.5f;
	line.start[1] = start[1] + 0.5f;
	line.end[0] = end[0] + 0.5f;
	line.end[1] = end[1] + 0.5f;
	fill_line_infos(&line);
	return (line);
}

void	fill_line_infos(t_line *line)
{
	line->error_x = abs((line->end[0] - line->start[0]));
	line->error_y = abs((line->end[1] - line->start[1]));
	line->diff_x = 2 * line->error_x;
	line->diff_y = 2 * line->error_y;
	line->starting_error_x = line->error_x;
	line->starting_error_y = line->error_y;
	line->x_incr = 1;
	if (line->start[0] > line->end[0])
		line->x_incr = -1;
	line->y_incr = 1;
	if (line->start[1] > line->end[1])
		line->y_incr = -1;
}
