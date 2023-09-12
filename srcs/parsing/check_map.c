/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:23:42 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/12 16:17:53 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_enclosed_map(t_map *map);

int	check_map_and_player(t_data *data)
{
	int	err_code;

	err_code = check_player(&data->map, &data->player);
	if (err_code)
		parse_error_quit(data, err_code);
//	err_code = check_enclosed_map(&data->map);
//	if (err_code)
//		return (err_code);
	return (EXIT_SUCCESS);
}
