/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:52:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/26 15:12:27 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub.h"

//-----------------FUNCTION-----------------//
int		parsing(int argc, char **argv, t_data *data);
int		get_textures_and_colors(int fd, t_data *data);
int		parse_error_quit(t_data *data, int r);

void	flush_newline(char **array, int array_length);
void	free_textures_line(char *textures_line[4]);
int		get_line_no_whitespace(char *buff, char **line, int *data_got);
int		get_textures_line(char *buff, char *line_array[4],
			int *data_got, t_tracker *tracker);
int		get_color(char *buff, uint32_t color[2], int *data_got);

int		get_map(int fd, t_data *data);

int		check_map_and_player(t_data *data);

int	check_texture_format(char *textures_line[4]);

int		check_player(t_map *map, t_player *player);

//-----------------ERROR_MESSAGES-----------------//
# define ERM_ARGC "\033[1;31mcub3D: Usage: ./cub3D <map.cub>\n\033[0m"
# define ERC_ARGC 101
# define ERM_EXTENSION "\033[1;31mError\nWrong map file extension,\
	expected <.cub>\033[0m\n"
# define ERC_EXTENSION 102
# define ERM_ACCESS "\033[1;31mError\nCan't access map file: %s\033[0m\n"
# define ERC_ACCESS 103
# define ERM_TEXTURE_NORTH "\033[1;31mError\nCan't access \
texture for north\033[0m\n"
# define ERM_TEXTURE_SOUTH "\033[1;31mError\nCan't access \
texture for south\033[0m\n"
# define ERM_TEXTURE_EAST "\033[1;31mError\nCan't access \
texture for east\033[0m\n"
# define ERM_TEXTURE_WEST "\033[1;31mError\nCan't access \
texture for west\033[0m\n"
# define ERC_TEXTURE 104
# define ERM_NB_INFO "\033[1;31mError\nWrong number \
of info in provided file\033[0m\n"
# define ERC_NB_INFO 105
# define ERM_ARRAY_BIGGER "\033[1;31mError\n\
Wrong number of info on line %c\033[0m\n"
# define ERC_ARRAY_BIGGER 106
# define ERM_OOR_VALUE "\033[1;31mError\n\
Color value out of range\033[0m\n"
# define ERC_OOR_VALUE 107
# define ERM_NO_MAP  "\033[1;31mError\nNo map found \
in provided file\033[0m\n"
# define ERC_NO_MAP 108
# define ERM_UNCLOSED "\033[1;31mError\nUnclosed map\033[0m\n"
# define ERC_UNCLOSED 109
# define ERM_UNEXPECTED "\033[1;31mError\n\
Unexpected character \"%c\" at [%d][%d]\033[0m\n"
# define ERC_UNEXPECTED 110
# define ERM_PLAYER "\033[1;31mError\nMultiple player \
in provided file\033[0m\n"
# define ERC_PLAYER 111
# define ERM_NO_PLAYER "\033[1;31mError\nPlayer position not found\033[0m"
# define ERC_NO_PLAYER 112
# define STRANGE "\033[1;31mcub3D: Strange situation\033[0m\n"
# define STRANGE_CODE 4242
# define ERM_DUPLI "\033[1;31mError\nDuplicate textures \
info detected for %s\033[0m\n"
# define ERC_DUPLI 113
# define ERM_MISSING_C "\033[1;31mError\nMissing color value detected\033[0m\n"
# define ERC_MISSING_C 114
# define ERM_NOT_XPM "\033[1;31mError\nTexture for %s is not an XPM\033[0m\n"
# define ERC_NOT_XPM 115
# define ERM_WRONG_C "\033[1;31mError\nUnvalid color value\033[0m\n"
# define ERC_WRONG_C 116
# define EXIT_EOF 255
#endif
