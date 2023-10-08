/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:54:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/08 13:43:21 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		locate_player(t_map *map, t_player *player);
bool	player_char(char c);
void	set_player(bool *found, t_player *player,
			t_vec_2i cur, char orientation);

int	check_player(t_map *map, t_player *player)
{
	int			r_value;

	r_value = locate_player(map, player);
	if (r_value)
		return (r_value);
	return (EXIT_SUCCESS);
}

int	locate_player(t_map *map, t_player *player)
{
	t_vec_2i	cur;
	bool		player_found;

	player_found = false;
	cur.y = 0;
	while (cur.y < map->size.y)
	{
		cur.x = 0;
		while (map->content[cur.y][cur.x])
		{
			if (player_char(map->content[cur.y][cur.x]))
			{
				if (!player_found)
					set_player(&player_found, player, cur,
						map->content[cur.y][cur.x]);
				else
					return (ft_dprintf(2, ERM_PLAYER, ERC_PLAYER));
			}
			cur.x++;
		}
		cur.y++;
	}
	if (!player_found)
		return (ft_dprintf(2, ERM_NO_PLAYER), ERC_NO_PLAYER);
	return (EXIT_SUCCESS);
}

bool	player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

void	set_player(bool *found, t_player *player,
			t_vec_2i cur, char orientation)
{
	enum e_dir	dir;

	*found = true;
	dir = NORTH;
	if (orientation == 'S')
		dir = SOUTH;
	else if (orientation == 'E')
		dir = EAST;
	else if (orientation == 'W')
		dir = WEST;
	*player = init_player(dir, cur);
}
