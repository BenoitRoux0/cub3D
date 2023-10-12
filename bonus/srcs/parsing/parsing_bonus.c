/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:45 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/11 23:47:40 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

bool	unvalid_extension(char *map);
void	free_img(t_data *data, int i);

int	parsing(int argc, char **argv, t_data *data)
{
	int	fd;
	int	fd_2;
	int	fd_3;

	set_fallback_values(data);
	if (argc != 2)
		return (ft_dprintf(2, ERM_ARGC), parse_error_quit(data, ERC_ARGC));
	if (unvalid_extension(argv[1]))
		return (ft_dprintf(2, ERM_EXTENSION),
			parse_error_quit(data, ERC_EXTENSION));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, ERM_ACCESS, argv[1]),
			parse_error_quit(data, ERC_ACCESS));
	get_textures_and_colors(fd, data);
	get_map(fd, data);
	close(fd);
	fd_2 = open(argv[1], O_RDONLY);
	fd_3 = dup(fd_2);
	close(fd_2);
	get_sprites(fd_3, data);
	close(fd_3);
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
	if (data->fps_data.fps_str)
		free(data->fps_data.fps_str);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_array((void **)data->map.content);
	free_img(data, i);
	data->mlx = NULL;
	exit (r);
}

void	free_img(t_data *data, int i)
{
	while (++i < 4)
		if (data->map.walls_text[i] != data->fallback_wall)
			clear_img(data->map.walls_text[i]);
	if (data->map.door != data->fallback_sprite)
		clear_img(data->map.door);
	clear_sprites_img(data->map.sprites, data->fallback_sprite);
	if (data->fallback_sprite)
		clear_img(data->fallback_sprite);
	if (data->fallback_wall)
		clear_img(data->fallback_wall);
}
