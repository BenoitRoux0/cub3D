/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:11:36 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/08 16:39:41 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	flush_newline(char **array, int array_length)
{
	int	i;

	i = -1;
	if (!array_length)
		array_length = ft_array_length((void **)array);
	while (++i < array_length)
	{
		if (array[i][ft_strlen(array[i]) - 1] == '\n')
			array[i][ft_strlen(array[i]) - 1] = '\0';
	}
}

void	free_textures_line(char *textures_line[4])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (textures_line[i])
			free(textures_line[i]);
	}
}

void	get_line_no_whitespace(char *buff, char **line, int *data_got)
{
	int	i;

	i = 0;
	buff = &buff[2];
	while (buff[i] == ' ')
		i++;
	if (buff[i])
	{
		*line = ft_strdup(&buff[i]);
		(*data_got)++;
	}
	else
		line = NULL;
}

void	get_textures_line(char *buff, char *line_array[4], int *data_got)
{
	if (ft_strncmp(buff, "NO", 2) == 0)
		get_line_no_whitespace(buff, &line_array[NORTH], data_got);
	else if (ft_strncmp(buff, "SO", 2) == 0)
		get_line_no_whitespace(buff, &line_array[SOUTH], data_got);
	else if (ft_strncmp(buff, "WE", 2) == 0)
		get_line_no_whitespace(buff, &line_array[WEST], data_got);
	else if (ft_strncmp(buff, "EA", 2) == 0)
		get_line_no_whitespace(buff, &line_array[EAST], data_got);
}
