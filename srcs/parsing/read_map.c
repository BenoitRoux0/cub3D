/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:42:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/10 19:31:29 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		skip_newline(int fd, char **buff);
void	get_map_size(char **map, t_vec_2i *size);
void	fill_blank_with_space(char **map, t_vec_2i *size);

int	get_map(int fd, t_data *data)
{
	char	*buff;

	buff = get_next_line(fd);
	if (skip_newline(fd, &buff))
		return (parse_error_quit(data, ERC_NO_MAP));
	data->map.content = ft_calloc(2, sizeof (char *));
	if (!data->map.content)
		return (ft_dprintf(2, STRANGE), parse_error_quit(data, STRANGE_CODE));
	data->map.content[0] = ft_strdup(buff);
	if (!data->map.content[0])
		return (ft_dprintf(2, STRANGE), parse_error_quit(data, STRANGE_CODE));
	free(buff);
	buff = get_next_line(fd);
	while (buff && ft_strcmp(buff, "\n"))
	{
		data->map.content = (char **)ft_add_array_line
			((void **) data->map.content, buff);
		buff = get_next_line(fd);
	}
	flush_newline(data->map.content, 0);
	if (buff)
		free(buff);
	close(fd);
	return (get_map_size(data->map.content, &data->map.size), EXIT_SUCCESS);
}

int	skip_newline(int fd, char **buff)
{
	while (ft_strcmp(*buff, "\n") == 0)
	{
		free(*buff);
		*buff = get_next_line(fd);
	}
	if (!(*buff))
		return (close(fd), ft_dprintf(STDERR_FILENO, ERM_NO_MAP, ERC_NO_MAP));
	return (EXIT_SUCCESS);
}

void	get_map_size(char **map, t_vec_2i *size)
{
	int	y;
	int	last_x_len;

	size->y = ft_array_length((void **)map);
	y = 0;
	size->x = ft_strlen(map[y]);
	while (map[y])
	{
		last_x_len = ft_strlen(map[y]);
		if (last_x_len > size->x)
			size->x = last_x_len;
		y++;
	}
	fill_blank_with_space(map, size);
}

void	fill_blank_with_space(char **map, t_vec_2i *size)
{
	int		y;
	int		x;
	char	*buff;

	y = 0;
	while (y < size->y)
	{
		x = ft_strlen(map[y]);
		if (x < size->x)
		{
			buff = ft_strdup(map[y]);
			free(map[y]);
			map[y] = ft_calloc((size->x + 1), sizeof(char));
			ft_memset(map[y], ' ', size->x);
			ft_memmove(map[y], buff, x);
			free(buff);
		}
		y++;
	}
}
