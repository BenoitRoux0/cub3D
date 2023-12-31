/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:44:05 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/11 23:56:24 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	open_sprite(t_data *data, t_sprite *sprite, char *path);

int	set_sprite(t_data *data, t_sprite *sprite, char **sprite_line)
{
	int	i;

	i = 0;
	while (sprite_line[i])
	{
		if (sprite_line[i][0] == 'p')
		{
			if (open_sprite(data, sprite, &sprite_line[i][2]) != EXIT_SUCCESS)
				return (ERC_DUPLI_S);
		}
		else if (ft_strlen(sprite_line[i]) > 5)
			return (ft_dprintf(2, ERM_S_OOR), ERC_S_OOR);
		else if (sprite_line[i][0] == 'h')
			sprite->height = ft_atoi(&sprite_line[i][2]) * 0.01;
		else if (sprite_line[i][0] == 'x')
			sprite->x_pos = ft_atoi(&sprite_line[i][2]) * 0.01;
		else if (sprite_line[i][0] == 'y')
			sprite->y_pos = ft_atoi(&sprite_line[i][2]) * 0.01;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	open_sprite(t_data *data, t_sprite *sprite, char *path)
{
	char	*path_trimed;

	path_trimed = ft_strtrim(path, "p:");
	if (sprite->set)
	{
		free(path_trimed);
		ft_dprintf(2, ERM_DUPLI_S);
		return (ERC_DUPLI_S);
	}
	sprite->src = ft_xpm_to_img(data->mlx, path_trimed);
	sprite->set = true;
	free(path_trimed);
	return (EXIT_SUCCESS);
}
