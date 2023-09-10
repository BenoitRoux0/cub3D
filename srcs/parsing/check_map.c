/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:23:42 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/09 18:37:00 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_enclosed_map(t_map *map);
int	check_player(t_map *map, t_player *player);

int	check_map_and_player(t_data *data)
{
	int	err_code;

	err_code = check_enclosed_map(&data->map);
	if (err_code)
		return (err_code);
//	err_code = check_player(&data->map, &data->player);
//	if (err_code)
//		return (err_code);
	return (EXIT_SUCCESS);
}

int	check_enclosed_map(t_map *map)
{
	int	cur_pos[2];

	ft_memset(cur_pos, 0, sizeof(int) * 2);
	while (cur_pos[1] <= map->size[1])
	{
		while (cur_pos[0] <= map->size[0])
		{
			if (!valid_char(map->content, cur_pos))
				return (ft_dprintf(STDERR_FILENO, ERM_UNCLOSED), ERC_UNCLOSED);
		}
	}
	return (EXIT_SUCCESS);
}
