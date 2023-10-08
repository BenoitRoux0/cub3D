/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error_cjeck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:13:18 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/08 13:52:47 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

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
