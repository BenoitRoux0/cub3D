/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:16:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/08 16:40:09 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		get_textures_infos(int fd, char *textures_line[4], int color[2][3]);
int		open_texture(t_data *data, char *textures_line[4]);
int		get_line_info(char *buff, int *data_got,
			char *textures_line[4], int color[2][3]);

int	get_textures_and_colors(int fd, t_data *data)
{
	char	*textures_line[4];
	int		error_code;

	ft_memset(textures_line, 0, sizeof(char *) * 4);
	error_code = get_textures_infos(fd, textures_line, data->map.colors);
	if (error_code != EXIT_SUCCESS)
		return (free_textures_line(textures_line), error_code);
	flush_newline(textures_line, 4);
	error_code = open_texture(data, textures_line);
	if (error_code != EXIT_SUCCESS)
		return (free_textures_line(textures_line), error_code);
	free_textures_line(textures_line);
	return (EXIT_SUCCESS);
}

int	get_textures_infos(int fd, char *textures_line[4], int color[2][3])
{
	char	*buff;
	int		data_got;

	data_got = 0;
	while (data_got < 6)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (ft_isalpha(buff[0]))
		{
			get_line_info(buff, &data_got, textures_line, color);
			if (data_got > 100)
				return (data_got);
		}
		else if (buff[0] != '\n')
		{
			free(buff);
			break ;
		}
		free(buff);
	}
	if (data_got != 6)
		return (ft_dprintf(STDERR_FILENO, ERM_NB_INFO"\n"), ERC_NB_INFO);
	return (EXIT_SUCCESS);
}

int	open_texture(t_data *data, char *textures_line[4])
{
	data->map.walls_text[NORTH]
		= ft_xpm_to_img(data->mlx,
			textures_line[NORTH]);
	if (!data->map.walls_text[NORTH].content)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_NORTH"\n"), ERC_TEXTURE);
	data->map.walls_text[SOUTH]
		= ft_xpm_to_img(data->mlx,
			textures_line[SOUTH]);
	if (!data->map.walls_text[SOUTH].content)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_SOUTH"\n"), ERC_TEXTURE);
	data->map.walls_text[EAST]
		= ft_xpm_to_img(data->mlx,
			textures_line[EAST]);
	if (!data->map.walls_text[EAST].content)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_EAST"\n"), ERC_TEXTURE);
	data->map.walls_text[WEST]
		= ft_xpm_to_img(data->mlx,
			textures_line[WEST]);
	if (!data->map.walls_text[WEST].content)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_WEST"\n"), ERC_TEXTURE);
	return (EXIT_SUCCESS);
}

int	get_line_info(char *buff, int *data_got,
			char *textures_line[4], int color[2][3])
{
	int	code;

	if (ft_strncmp(buff, "NO", 2) == 0 || ft_strncmp(buff, "SO", 2) == 0
		|| ft_strncmp(buff, "WE", 2) == 0 || ft_strncmp(buff, "EA", 2) == 0)
		get_textures_line(buff, textures_line, data_got);
	else if (buff[0] == 'F' || buff[0] == 'C')
	{
		code = get_color(buff, color, data_got);
		if (code != EXIT_SUCCESS)
			return (free(buff), *data_got = code, code);
	}
	return (EXIT_SUCCESS);
}
