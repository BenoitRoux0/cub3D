/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint32_t_color_convs_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:15:19 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 14:16:31 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

uint32_t	color_to_uint32_t(t_color color)
{
	return (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
}

t_color	uint32_t_to_color(uint32_t int_color)
{
	t_color	color;

	ft_bzero(&color, sizeof(t_color));
	color.a = ((int_color >> 24) & 0xFF);
	color.r = ((int_color >> 16) & 0xFF);
	color.g = ((int_color >> 8) & 0xFF);
	color.b = ((int_color) & 0xFF);
	return (color);
}
