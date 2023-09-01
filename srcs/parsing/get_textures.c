/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:16:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/01 11:35:35 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	flush_newline(char *array[4]);
int		get_textures_lines(int fd, char *textures_line[4]);

int	get_textures(int fd, t_data *data, char *map_path)
{
	char	*texture_line[4];

	if (get_textures_lines(fd, texture_line) == EXIT_FAILURE)
		return (ft_dprintf(STDERR_FILENO, ERM_MISS_TEXTURE), ERC_MISS_TEXTURE);
	close(fd);
	flush_newline(texture_line);
	fd = open(map_path, O_RDONLY);
	(void)data;
	return (EXIT_SUCCESS);
}

int	get_textures_lines(int fd, char *textures_line[4])
{
	int		c_line;
	char	*buff;

	c_line = -1;
	while (++c_line < 4)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		else if (ft_strncmp(buff, "NO", 2) == 0)
			textures_line[NORTH] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "SO", 2) == 0)
			textures_line[SOUTH] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "WE", 2) == 0)
			textures_line[WEST] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "EA", 2) == 0)
			textures_line[EAST] = ft_strdup(&buff[3]);
		else
			c_line--;
		free(buff);
	}
	if (c_line != 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	flush_newline(char *array[4])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (array[i][ft_strlen(array[i]) - 1] == '\n')
			array[i][ft_strlen(array[i]) - 1] = '\0';
	}
}
