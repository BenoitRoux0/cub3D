/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:22:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/14 10:54:51 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color_atoi(uint32_t *color, char **value_split);

int	get_color(char *buff, uint32_t color[2], int *data_got)
{
	char	**first_split;
	char	**value_split;
	int		color_code;

	first_split = ft_split(buff, ' ');
	if (ft_array_length((void **)first_split) != 2)
		return (ft_dprintf(STDERR_FILENO, ERM_ARRAY_BIGGER,
				first_split[0]), ft_free_split(first_split), ERC_ARRAY_BIGGER);
	value_split = ft_split(first_split[1], ',');
	if (ft_array_length((void **)value_split) != 3)
		return (ft_dprintf(STDERR_FILENO, ERM_ARRAY_BIGGER,
				first_split[0]), ft_free_split(first_split),
			ft_free_split(value_split), ERC_ARRAY_BIGGER);
	if (first_split[0][0] == 'C')
		color_code = color_atoi(&color[CEILING], value_split);
	else
		color_code = color_atoi(&color[FLOOR], value_split);
	ft_free_split(first_split);
	if (color_code != EXIT_SUCCESS)
		return (color_code);
	ft_free_split(value_split);
	(*data_got)++;
	return (EXIT_SUCCESS);
}

int	color_atoi(uint32_t *color, char **value_split)
{
	int		i;
	int		color_comps[3];

	color_comps[0] = ft_atoi(value_split[0]);
	color_comps[1] = ft_atoi(value_split[1]);
	color_comps[2] = ft_atoi(value_split[2]);
	i = 0;
	while (i < 3)
	{
		if (color_comps[i] < 0 || color_comps[i] > 255)
			return (ft_free_split(value_split),
				ft_dprintf(STDERR_FILENO, ERM_OOR_VALUE), ERC_OOR_VALUE);
		i++;
	}
	*color = (color_comps[0] << 16) + (color_comps[1] << 8) + color_comps[2];
	return (EXIT_SUCCESS);
}
