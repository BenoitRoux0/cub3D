/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:45 by gd-harco          #+#    #+#             */
/*   Updated: 2023/08/18 11:20:05 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	unvalid_extension(char *map);
int		get_texture(int fd, t_data *data);

int	parsing(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		return (printf(ERR_ARGC), ERC_ARGC);
	if (unvalid_extension(argv[1]))
		return (printf(ERR_EXTENSION), ERC_EXTENSION);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf(ERR_ACCESS"%s\n", argv[1]), ERC_ACCESS);
	(void)data;
//	if (get_texture(fd, data) == EXIT_FAILURE)
//		return (ERC_TEXTURE);
	//TODO: get map, get player
	return (0);
}

bool	unvalid_extension(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 1] != 'b' || map[i - 2] != 'u'
		|| map[i - 3] != 'c' || map[i - 4] != '.')
		return (true);
	return (false);
}
