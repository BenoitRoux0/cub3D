/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:23:42 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/13 12:58:49 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_enclosed_map(t_map *map, t_player player);
int	flood_algo(char **map, t_vec_2i pos, t_vec_2i size);

int	check_map_and_player(t_data *data)
{
	int	err_code;

	err_code = check_player(&data->map, &data->player);
	if (err_code)
		parse_error_quit(data, err_code);
	err_code = check_enclosed_map(&data->map, data->player);
	if (err_code)
		parse_error_quit(data, err_code);
	return (EXIT_SUCCESS);
}

int	check_enclosed_map(t_map *map, t_player player)
{
	t_vec_2i	pos;
	char		**map_copy;

	pos.x = (int)player.pos[0] / CELL_SIZE;
	pos.y = (int)player.pos[1] / CELL_SIZE;
	map_copy = (char **)ft_array_dup((void **)map->content, false, true);
	if (flood_algo(map_copy, pos, map->size))
		return (ft_free_array((void **)map_copy),
			ft_dprintf(2, ERM_UNCLOSED), ERC_UNCLOSED);
	return (ft_free_array((void **)map_copy), EXIT_SUCCESS);
}

int	flood_algo(char **map, t_vec_2i pos, t_vec_2i size)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return (ERC_UNCLOSED);
	if (map[pos.y][pos.x] == '1')
		return (EXIT_SUCCESS);
	if (map[pos.y][pos.x] == ' ')
		return (ERC_UNCLOSED);
	map[pos.y][pos.x] = '1';
	if (flood_algo(map, (t_vec_2i){pos.x + 1, pos.y}, size))
		return (ERC_UNCLOSED);
	if (flood_algo(map, (t_vec_2i){pos.x - 1, pos.y}, size))
		return (ERC_UNCLOSED);
	if (flood_algo(map, (t_vec_2i){pos.x, pos.y + 1}, size))
		return (ERC_UNCLOSED);
	if (flood_algo(map, (t_vec_2i){pos.x, pos.y - 1}, size))
		return (ERC_UNCLOSED);
	return (EXIT_SUCCESS);
}
