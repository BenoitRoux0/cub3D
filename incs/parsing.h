/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:52:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/08/18 11:19:48 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub.h"


int	parsing(int argc, char **argv, t_data *data);
int	get_texture(int fd, t_data *data);


//-------Error Message-------//
# define ERM_ARGC "cub3D: Usage: ./cub3D <map.cub>\n"
# define ERC_ARGC 101
# define ERM_EXTENSION "cub3D: Error: wrong map file extension,\
	expected <.cub>\n"
# define ERC_EXTENSION 102
# define ERM_ACCESS "cub3D: Error: can't access map file: "
# define ERC_ACCESS 103
# define ERM_TEXTURE_NORTH "cub3D: Error: can't access texture for north"
# define ERM_TEXTURE_SOUTH "cub3D: Error: can't access texture for south"
# define ERM_TEXTURE_EAST "cub3D: Error: can't access texture for east"
# define ERM_TEXTURE_WEST "cub3D: Error: can't access texture for west"
# define ERC_TEXTURE 104
#endif
