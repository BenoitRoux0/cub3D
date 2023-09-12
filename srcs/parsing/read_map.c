/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:42:54 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/11 17:32:15 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		skip_newline(int fd, char **buff);
void	get_map_size(char **map, t_vec_2i *size);

int	get_map(int fd, t_data *data)
{
	char	*buff;
	int		r_code;

	buff = get_next_line(fd);
	r_code = skip_newline(fd, &buff);
	if (r_code != EXIT_SUCCESS)
		return (r_code);
	data->map.content = ft_calloc(2, sizeof (char *));
	if (!data->map.content)
		return (-1);
	data->map.content[0] = ft_strdup(buff);
	free(buff);
	buff = get_next_line(fd);
	while (buff && ft_strcmp(buff, "\n"))
	{
		data->map.content = (char **)ft_add_array_line
			((void **)data->map.content, buff);
		buff = get_next_line(fd);
	}
	flush_newline(data->map.content, 0);
	if (buff)
		free(buff);
	close(fd);
	get_map_size(data->map.content, &data->map.size);
	return (EXIT_SUCCESS);
}

int	skip_newline(int fd, char **buff)
{
	while (ft_strcmp(*buff, "\n") == 0)
	{
		free(*buff);
		*buff = get_next_line(fd);
	}
	if (!(*buff))
		return (ft_dprintf(STDERR_FILENO, ERM_NO_MAP, 108));
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
}
