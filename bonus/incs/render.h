/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:24:38 by beroux            #+#    #+#             */
/*   Updated: 2023/08/15 15:19:05 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub.h"

// -----------------FUNCTION-----------------//
int	render(t_data *data);
int	raycast(t_data *data);
int	ray_collide_horiz(double vector[2], t_ray *ray, t_map map);
int	ray_collide_vert(double vector[2], t_ray *ray, t_map map);


#endif