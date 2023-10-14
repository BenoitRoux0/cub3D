/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_doors_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:40:54 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 16:53:33 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	fill_doors_map_line(t_doors_map doors_map, t_map map, int line);

t_doors_map	create_doors_map(t_map map)
{
	t_doors_map	doors_map;
	int			i;

	doors_map.size[0] = map.size.x;
	doors_map.size[1] = map.size.y;
	doors_map.content = ft_calloc(doors_map.size[1], sizeof (int *));
	if (!doors_map.content)
		return (doors_map);
	i = 0;
	while (i < doors_map.size[1])
	{
		doors_map.content[i] = ft_calloc(doors_map.size[0], sizeof (int));
		if (!doors_map.content[i])
			return (doors_map);
		fill_doors_map_line(doors_map, map, i);
		i++;
	}
	return (doors_map);
}

static void	fill_doors_map_line(t_doors_map doors_map, t_map map, int line)
{
	int	i;

	i = 0;
	while (i < doors_map.size[0])
	{
		doors_map.content[line][i] = (map.content[line][i] == 'D') * 100;
		i++;
	}
}
