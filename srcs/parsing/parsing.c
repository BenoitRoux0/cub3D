/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:45 by gd-harco          #+#    #+#             */
/*   Updated: 2023/08/31 14:36:00 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	unvalid_extension(char *map);
int		get_textures_and_colors(int fd, t_data *data);

int	parsing(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		return (printf(ERM_ARGC), ERC_ARGC);
	if (unvalid_extension(argv[1]))
		return (printf(ERM_EXTENSION), ERC_EXTENSION);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf(ERM_ACCESS"%s\n", argv[1]), ERC_ACCESS);
	(void)data;
	if (get_textures_and_colors(fd, data) != EXIT_SUCCESS)
		return (ERC_TEXTURE);
	//TODO: get map, get player
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
