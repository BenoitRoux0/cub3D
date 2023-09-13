/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:45 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/13 17:08:24 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	unvalid_extension(char *map);
int		get_textures_and_colors(int fd, t_data *data);

int	parsing(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		return (ft_dprintf(2, ERM_ARGC), parse_error_quit(data, ERC_ARGC));
	if (unvalid_extension(argv[1]))
		return (ft_dprintf(2, ERM_EXTENSION), parse_error_quit(data, ERC_EXTENSION));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, ERM_ACCESS, argv[1]),
			parse_error_quit(data, ERC_ACCESS));
	(void)data;
	get_textures_and_colors(fd, data);
	get_map(fd, data);
	check_map_and_player(data);
	return (0);
}

bool	unvalid_extension(char *map)
{
	int	i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(&map[i], ".cub", 4) != 0)
		return (true);
	return (false);
}

int	parse_error_quit(t_data *data, int r)
{
	int	i;

	i = -1;
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_array((void **)data->map.content);
	while (++i < 4)
		clear_img(data->map.walls_text[i]);
	data->mlx = NULL;
	exit (r);
}
