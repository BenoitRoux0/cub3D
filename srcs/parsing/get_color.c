/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:22:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/23 22:33:43 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color_atoi(uint32_t *color, char **value_split);

int	get_color(char *buff, uint32_t color[2], int *data_got)
{
	int			color_code;
	uint32_t	*dest;
	char		**split;
	char		*tmp;

	if (buff[0] == 'C')
		dest = &color[CEILING];
	else
		dest = &color[FLOOR];
	tmp = &buff[1];
	tmp = ft_strtrim(tmp, " ");
	if (!tmp)
		return (ft_dprintf(STDERR_FILENO, STRANGE), STRANGE_CODE);
	split = ft_split(tmp, ',');
	if (!split)
		return (ft_dprintf(STDERR_FILENO, STRANGE), STRANGE_CODE);
	if (ft_array_length((void **)split) != 3)
		return (ft_dprintf(STDERR_FILENO, ERM_ARRAY_BIGGER,
				buff[0]), ft_free_split(split), free(tmp),
			*data_got = ERC_ARRAY_BIGGER);
	color_code = color_atoi(dest, split);
	if (color_code != EXIT_SUCCESS)
		return (ft_free_split(split), free(tmp), *data_got = color_code);
	(*data_got)++;
	return (ft_free_split(split), free(tmp), color_code);
}

int	color_atoi(uint32_t *color, char **value_split)
{
	int		i;
	int		color_comps[3];

	if (value_split[2][0] == '\n')
		return (ft_dprintf(STDERR_FILENO, ERM_MISSING_C), ERC_MISSING_C);
	color_comps[0] = ft_atoi(value_split[0]);
	color_comps[1] = ft_atoi(value_split[1]);
	color_comps[2] = ft_atoi(value_split[2]);
	if (errno == 20)
		return (ft_dprintf(STDERR_FILENO, ERM_WRONG_C), ERC_WRONG_C);
	i = 0;
	while (i < 3)
	{
		if (color_comps[i] < 0 || color_comps[i] > 255)
			return (ft_dprintf(STDERR_FILENO, ERM_OOR_VALUE), ERC_OOR_VALUE);
		i++;
	}
	*color = (color_comps[0] << 16) + (color_comps[1] << 8) + color_comps[2];
	return (EXIT_SUCCESS);
}
