/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:22:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/02 15:43:29 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color_atoi(int color[3], char **value_split);

int	get_color(char *buff, int color[2][3], int *data_got)
{
	char	**first_split;
	char	**value_split;

	first_split = ft_split(buff, ' ');
	if (ft_array_length((void **)first_split) != 2)
		return (ft_dprintf(STDERR_FILENO, ERM_ARRAY_BIGGER "%s\n",
				first_split[0]), ft_free_split(first_split), ERC_ARRAY_BIGGER);
	value_split = ft_split(first_split[1], ',');
	if (first_split[0][0] == 'C')
		color_atoi(color[CEILING], value_split);
	else
		color_atoi(color[FLOOR], value_split);
	(void)data_got;
	return (EXIT_SUCCESS);
}

int	color_atoi(int color[3], char **value_split)
{
	int	i;

	color[0] = ft_atoi(value_split[0]);
	color[1] = ft_atoi(value_split[1]);
	color[2] = ft_atoi(value_split[2]);
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (ft_free_split(value_split),
				ft_dprintf(STDERR_FILENO, ERM_OOR_VALUE"\n"), ERC_OOR_VALUE);
	}
}
