/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:13:42 by beroux            #+#    #+#             */
/*   Updated: 2023/09/18 15:54:12 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "types_bonus.h"

t_uint_img	*create_map(t_map map);
t_uint_img	*cut_minimap(t_data *data);
void		minimap_draw(t_data *data);

#endif