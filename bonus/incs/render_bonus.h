/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:38 by beroux            #+#    #+#             */
/*   Updated: 2023/10/07 19:30:56 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "cub_bonus.h"

// -----------------FUNCTION-----------------//
int		render(t_data *data);
int		raycast(t_data *data);
int		ray_collide_horiz(double vector[2], t_ray *ray, t_map map);
int		ray_collide_vert(double vector[2], t_ray *ray, t_map map);
int		fill_color(t_uint_img *dst, uint32_t floor, uint32_t ceiling);
int		render_to_window(t_data *data);
void	init_angles(t_data *data);
int		cast_vert(double start[2], t_angle_data *angle, \
							t_ray *ray, t_map map);
int		cast_horiz(double start[2], t_angle_data *a, \
							t_ray *ray, t_map map);
#endif
