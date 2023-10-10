/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:16:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/10 16:49:30 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	get_textures_infos(int fd, char *textures_line[4], uint32_t color[2]);
int	open_texture(t_data *data, char *textures_line[4]);
int	get_line_info(char *buff, int *data_got,
		char *textures_line[4], uint32_t color[2]);
int	get_info(int fd, int *data_got, char *textures_line[4], uint32_t color[2]);

int	get_textures_and_colors(int fd, t_data *data)
{
	char	*textures_line[4];
	int		error_code;

	ft_memset(textures_line, 0, sizeof(char *) * 4);
	error_code = get_textures_infos(fd, textures_line, data->map.colors);
	if (error_code)
		return (free_textures_line(textures_line),
			close(fd), parse_error_quit(data, error_code));
	flush_newline(textures_line, 4);
	error_code = open_texture(data, textures_line);
	if (error_code)
		return (free_textures_line(textures_line), parse_error_quit(data,
				error_code));
	free_textures_line(textures_line);
	flip_horizontaly(data->map.walls_text[SO]);
	flip_horizontaly(data->map.walls_text[WEST]);
	return (EXIT_SUCCESS);
}

int	get_textures_infos(int fd, char *textures_line[4], uint32_t color[2])
{
	int	data_got;
	int	r;

	data_got = 0;
	r = 0;
	while (data_got < 6 && r != EXIT_EOF)
		r = get_info(fd, &data_got, textures_line, color);
	if (data_got == STRANGE_CODE)
		return (STRANGE_CODE);
	if (data_got == ERC_DUPLI)
		return (ERC_DUPLI);
	if (data_got == ERC_OOR_VALUE)
		return (ERC_OOR_VALUE);
	if (data_got == ERC_MISSING_C)
		return (ERC_MISSING_C);
	if (data_got == ERC_ARRAY_BIGGER)
		return (ERC_ARRAY_BIGGER);
	if (data_got == ERC_WRONG_C)
		return (ERC_WRONG_C);
	if (data_got != 6)
		return (ft_dprintf(STDERR_FILENO, ERM_NB_INFO"\n"), ERC_NB_INFO);
	return (EXIT_SUCCESS);
}

int	open_texture(t_data *data, char *textures_line[4])
{
	data->map.walls_text[NO] = ft_xpm_to_img(data->mlx, textures_line[NO]);
	data->map.walls_text[SO] = ft_xpm_to_img(data->mlx, textures_line[SO]);
	data->map.walls_text[EAST] = ft_xpm_to_img(data->mlx, textures_line[EAST]);
	data->map.walls_text[WEST] = ft_xpm_to_img(data->mlx, textures_line[WEST]);
	set_fallback_wall(data);
	return (EXIT_SUCCESS);
}

int	get_line_info(char *buff, int *data_got,
		char *textures_line[4], uint32_t color[2])
{
	static t_tracker	tracker;
	int					code;

	if (ft_strncmp(buff, "NO", 2) == 0 || ft_strncmp(buff, "SO", 2) == 0
		|| ft_strncmp(buff, "WE", 2) == 0 || ft_strncmp(buff, "EA", 2) == 0)
	{
		code = get_textures_line(buff, textures_line, data_got, &tracker);
		if (code != EXIT_SUCCESS)
			return (free(buff), *data_got = code);
	}
	else if (buff[0] == 'F' || buff[0] == 'C')
	{
		tracker.color++;
		if (tracker.color > 2)
		{
			*data_got = ERC_DUPLI_C;
			return (ft_dprintf(2, ERM_DUPLI_C, buff[0]), free(buff), *data_got);
		}
		code = get_color(buff, color, data_got);
		if (code != EXIT_SUCCESS)
			return (free(buff), *data_got = code);
	}
	return (EXIT_SUCCESS);
}

int	get_info(int fd, int *data_got, char *textures_line[4], uint32_t color[2])
{
	char	*buff;
	char	*pre_buff;

	pre_buff = get_next_line(fd);
	if (!pre_buff)
		return (EXIT_EOF);
	if (pre_buff[0] == '\n')
		return (free(pre_buff), EXIT_SUCCESS);
	buff = ft_strtrim(pre_buff, " ");
	if (!buff)
		return (free(pre_buff), ft_dprintf(2, STRANGE), STRANGE_CODE);
	if (ft_isalpha(buff[0]))
	{
		get_line_info(buff, data_got, textures_line, color);
		if (*data_got > 100)
			return (free(pre_buff), *data_got);
	}
	return (free(buff), free(pre_buff), EXIT_SUCCESS);
}
