/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:42:18 by beroux            #+#    #+#             */
/*   Updated: 2023/02/03 18:04:54 by beroux           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

uint32_t	mix_colors(uint32_t bg, uint32_t fg)
{
	t_color	color_fg;

	color_fg = uint32_t_to_color(fg);
	if (color_fg.a == 255)
		return (bg);
	return (fg);
}
