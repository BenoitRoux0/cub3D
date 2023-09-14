/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:23:42 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/14 17:55:36 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_enclosed_map(t_map *map, t_player player);
int	flood_algo(char **map, t_vec_2i pos, t_vec_2i size, int *ret);

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
	int			ret;

	ret = 0;
	pos.x = (int)player.pos[0] / CELL_SIZE;
	pos.y = (int)player.pos[1] / CELL_SIZE;
	map_copy = (char **)ft_array_dup((void **)map->content, false, true);
	map_copy[pos.y][pos.x] = '0';
	flood_algo(map_copy, pos, map->size, &ret);
	if (ret)
		return (ft_free_array((void **)map_copy), ret);
	return (ft_free_array((void **)map_copy), EXIT_SUCCESS);
}

int	flood_algo(char **map, t_vec_2i pos, t_vec_2i size, int *ret)
{
	if (*ret)
		return (*ret);
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return (ft_dprintf(2, ERM_UNCLOSED), ERC_UNCLOSED);
	if (map[pos.y][pos.x] != '0' && map[pos.y][pos.x]
		!= '1' && map[pos.y][pos.x] != ' ')
		return (ft_dprintf(2, ERM_UNEXPECTED, map[pos.y][pos.x],
			pos.x, pos.y), ERC_UNEXPECTED);
	if (map[pos.y][pos.x] == '1')
		return (EXIT_SUCCESS);
	if (map[pos.y][pos.x] == ' ' && (pos.x == 0 || pos.x == size.x - 1
			|| pos.y == 0 || pos.y == size.y - 1))
		return (ft_dprintf(2, ERM_UNCLOSED), ERC_UNCLOSED);
	map[pos.y][pos.x] = '1';
	*ret = flood_algo(map, (t_vec_2i){pos.x + 1, pos.y}, size, ret);
	*ret = flood_algo(map, (t_vec_2i){pos.x - 1, pos.y}, size, ret);
	*ret = flood_algo(map, (t_vec_2i){pos.x, pos.y + 1}, size, ret);
	*ret = flood_algo(map, (t_vec_2i){pos.x, pos.y - 1}, size, ret);
	return (*ret);
}
