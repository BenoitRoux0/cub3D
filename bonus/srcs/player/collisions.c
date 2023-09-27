/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:41 by beroux            #+#    #+#             */
/*   Updated: 2023/09/26 18:58:10 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static double	dist_to_wall_up(double x, double y, t_map *map);
static double	dist_to_wall_down(double x, double y, t_map *map);
static double	dist_to_wall_left(double x, double y, t_map *map);
static double	dist_to_wall_right(double x, double y, t_map *map);

void	collide(t_data *data, double pos[2], double next_pos[2])
{
	double	left_dist;
	double	right_dist;
	double	up_dist;
	double	down_dist;

	left_dist = dist_to_wall_left(next_pos[0], pos[1], &data->map);
	right_dist = dist_to_wall_right(next_pos[0], pos[1], &data->map);
	up_dist = dist_to_wall_up(pos[0], next_pos[1], &data->map);
	down_dist = dist_to_wall_down(pos[0], next_pos[1], &data->map);
	if (left_dist <= 2)
		next_pos[0] = next_pos[0] + 2;
	if (right_dist <= 2)
		next_pos[0] = next_pos[0] + 2;
	if (up_dist <= 2)
		next_pos[1] = next_pos[1] - 2;
	if (down_dist <= 2)
		next_pos[1] = next_pos[1] + 2;
}

static double	dist_to_wall_right(double x, double y, t_map *map)
{
	if (map->content[(int) y / CELL_SIZE][(int) x / CELL_SIZE] == '1')
		return (0);
	return (CELL_SIZE - fmod(x, CELL_SIZE) + dist_to_wall_right(x + (CELL_SIZE - fmod(x, CELL_SIZE)), y, map));
}

static double	dist_to_wall_left(double x, double y, t_map *map)
{
	if (map->content[(int) y / CELL_SIZE][(int) x / CELL_SIZE] == '1')
		return (0);
	if (!fmod(x, CELL_SIZE) && map->content[(int) y / CELL_SIZE][((int) x - CELL_SIZE - 1) / CELL_SIZE] == '1')
		return (0);
	if (fmod(x, CELL_SIZE))
		return (fmod(x, CELL_SIZE) + dist_to_wall_left((int)(x / CELL_SIZE) * CELL_SIZE, y, map));
	return (CELL_SIZE + dist_to_wall_left(x / CELL_SIZE * CELL_SIZE - CELL_SIZE, y, map));
}

static double	dist_to_wall_down(double x, double y, t_map *map)
{
	if (map->content[(int) y / CELL_SIZE][(int) x / CELL_SIZE] == '1')
		return (0);
	if (fmod(y, CELL_SIZE))
		return (CELL_SIZE - fmod(y, CELL_SIZE) + dist_to_wall_down(x, y / CELL_SIZE * CELL_SIZE + CELL_SIZE, map));
	return (CELL_SIZE + dist_to_wall_down(x, y / CELL_SIZE * CELL_SIZE + CELL_SIZE, map));
}

static double	dist_to_wall_up(double x, double y, t_map *map)
{
	if (map->content[(int) y / CELL_SIZE][(int) x / CELL_SIZE] == '1')
		return (0);
	if (map->content[(int) (y - 1) / CELL_SIZE][(int) x / CELL_SIZE] == '1')
		return (0);
	if (fmod(y, CELL_SIZE))
		return (fmod(y, CELL_SIZE) + dist_to_wall_up(x, (int)(y / CELL_SIZE) * CELL_SIZE, map));
	return (CELL_SIZE + dist_to_wall_up(x, y / CELL_SIZE * CELL_SIZE - CELL_SIZE, map));
}