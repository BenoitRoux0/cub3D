/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:38 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 15:47:42 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub_bonus.h"

// -----------------FUNCTION-----------------//
int	render(t_data *data);
int	raycast(t_data *data);
int	ray_collide_horiz(double vector[2], t_ray *ray, t_map map);
int	ray_collide_vert(double vector[2], t_ray *ray, t_map map);
int	fill_color(t_uint_img *dst, uint32_t floor, uint32_t ceiling);


#endif
