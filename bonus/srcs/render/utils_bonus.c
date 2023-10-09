/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:16:55 by beroux            #+#    #+#             */
/*   Updated: 2023/10/09 08:52:36 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_angle_data	angles_sum(t_angle_data a, t_angle_data b)
{
	t_angle_data	c;

	c.deg = fmod((fmod(a.deg + b.deg, 360) + 360), 360);
	c.rad = c.deg * M_PI_4 / 45;
	c.angle_sin = \
				a.angle_sin * b.angle_cos + \
				a.angle_cos * b.angle_sin;
	c.angle_cos = \
				a.angle_cos * b.angle_cos - \
				a.angle_sin * b.angle_sin;
	return (c);
}
