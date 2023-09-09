/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:52:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/08 17:01:07 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub.h"

//-----------------FUNCTION-----------------//
int		parsing(int argc, char **argv, t_data *data);
int		get_textures_and_colors(int fd, t_data *data);

void	flush_newline(char **array, int array_length);
void	free_textures_line(char *textures_line[4]);
void	get_line_no_whitespace(char *buff, char **line, int *data_got);
void	get_textures_line(char *buff, char *line_array[4], int *data_got);

int		get_color(char *buff, int color[2][3], int *data_got);

int		get_map(int fd, t_data *data);

int		check_map_and_player(t_data *data);

//-----------------ERROR_MESSAGES-----------------//
# define ERM_ARGC "\033[1;31mcub3D: Usage: ./cub3D <map.cub>\n\033[0m"
# define ERC_ARGC 101
# define ERM_EXTENSION "\033[1;31mcub3D: Error: wrong map file extension,\
	expected <.cub>\n\033[0m"
# define ERC_EXTENSION 102
# define ERM_ACCESS "\033[1;31mcub3D: Error: can't access map file: "
# define ERC_ACCESS 103
# define ERM_TEXTURE_NORTH "\033[1;31mcub3D: Error: can't access \
texture for north\033[0m"
# define ERM_TEXTURE_SOUTH "\033[1;31mcub3D: Error: can't access \
texture for south\033[0m"
# define ERM_TEXTURE_EAST "\033[1;31mcub3D: Error: can't access \
texture for east\033[0m"
# define ERM_TEXTURE_WEST "\033[1;31mcub3D: Error: can't access \
texture for west\033[0m"
# define ERC_TEXTURE 104
# define ERM_NB_INFO "\033[1;31mcub3D: Error: wrong number \
of info in provided file\033[0m"
# define ERC_NB_INFO 105
# define ERM_ARRAY_BIGGER "\033[1;31mcub3D: Error: to many info on line "
# define ERC_ARRAY_BIGGER 106
# define ERM_OOR_VALUE "\033[1;31mcub3D: Error: color value out of range\033[0m"
# define ERC_OOR_VALUE 107
# define ERM_NO_MAP  "\033[1;31mcub3D: Error: No map found \
in provided file\033[0m"
# define ERC_NO_MAP 108
#endif
