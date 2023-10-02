/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:38 by beroux            #+#    #+#             */
/*   Updated: 2023/10/01 01:15:37 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "cub_bonus.h"

// -----------------FUNCTION-----------------//
int		render(t_data *data);
int		raycast(t_data *data);
int		ray_collide_horiz(t_data *data, double vector[2], \
							t_ray *ray, t_map map);
int		ray_collide_vert(t_data *data, double vector[2], \
							t_ray *ray, t_map map);
int		fill_color(t_uint_img *dst, uint32_t floor, uint32_t ceiling);
int		render_to_window(t_data *data);
void	init_angles(t_data *data);

#endif
