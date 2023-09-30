/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error_cjeck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:13:18 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/25 16:21:20 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	check_texture_format(char *textures_line[4])
{
	int	i;

	i = ft_strlen(textures_line[NORTH]) - 4;
	if (ft_strncmp(&textures_line[NORTH][i], ".xpm", 4) != 0)
		return (ft_dprintf(2, ERM_NOT_XPM, "north"), ERC_NOT_XPM);
	i = ft_strlen(textures_line[SOUTH]) - 4;
	if (ft_strncmp(&textures_line[SOUTH][i], ".xpm", 4) != 0)
		return (ft_dprintf(2, ERM_NOT_XPM, "south"), ERC_NOT_XPM);
	i = ft_strlen(textures_line[EAST]) - 4;
	if (ft_strncmp(&textures_line[EAST][i], ".xpm", 4) != 0)
		return (ft_dprintf(2, ERM_NOT_XPM, "east"), ERC_NOT_XPM);
	i = ft_strlen(textures_line[WEST]) - 4;
	if (ft_strncmp(&textures_line[WEST][i], ".xpm", 4) != 0)
		return (ft_dprintf(2, ERM_NOT_XPM, "west"), ERC_NOT_XPM);
	return (EXIT_SUCCESS);
}

int	check_dup(char *buff, t_tracker *tracker)
{
	if (ft_strncmp(buff, "NO", 2) == 0 && tracker->north)
		return (ft_dprintf(2, ERM_DUPLI, "north"), true);
	else if (ft_strncmp(buff, "SO", 2) == 0 && tracker->south)
		return (ft_dprintf(2, ERM_DUPLI, "south"), true);
	else if (ft_strncmp(buff, "WE", 2) == 0 && tracker->west)
		return (ft_dprintf(2, ERM_DUPLI, "west"), true);
	else if (ft_strncmp(buff, "EA", 2) == 0 && tracker->east)
		return (ft_dprintf(2, ERM_DUPLI, "east"), true);
	return (false);
}
