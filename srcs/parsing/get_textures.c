/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:16:09 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/01 16:12:32 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	flush_newline(char *array[4]);
int		get_textures_infos(int fd, char *textures_line[4], int color[2][3]);
void	free_textures_line(char *textures_line[4]);
int		open_texture(t_data *data, char *textures_line[4]);

int	get_textures(int fd, t_data *data, char *map_path)
{
	char	*textures_line[4];
	int		color[2][3];
	int		open_textures_code;

	ft_memset(textures_line, 0, sizeof(char *) * 4);

	if (get_textures_infos(fd, textures_line, NULL) == EXIT_FAILURE)
		return (free_textures_line(textures_line),
			ft_dprintf(STDERR_FILENO, ERM_MISS_TEXTURE"\n"), ERC_MISS_TEXTURE);
	close(fd);
	flush_newline(textures_line);
	open_textures_code = open_texture(data, textures_line);
	if (open_textures_code != EXIT_SUCCESS)
		return (free_textures_line(textures_line), ERC_TEXTURE);
	free_textures_line(textures_line);
	(void)map_path;
	return (EXIT_SUCCESS);
}

//TODO: Il peut y avoir autant d'espece que voulu entre la cle et le  contenue (mais pas de newline);
int	get_textures_infos(int fd, char *textures_line[4], int color[2][3])
{
	int		c_line;
	char	*buff;

	c_line = -1;
	while (++c_line < 4)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		else if (ft_strncmp(buff, "NO", 2) == 0)
			textures_line[NORTH] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "SO", 2) == 0)
			textures_line[SOUTH] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "WE", 2) == 0)
			textures_line[WEST] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "EA", 2) == 0)
			textures_line[EAST] = ft_strdup(&buff[3]);
		else if (ft_strncmp(buff, "F", 1) || ft_strncmp(buff, "C", 1))
			get_colors(buff, color);
		else
			c_line--;
		free(buff);
	}
	if (c_line != 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	flush_newline(char *array[4])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (array[i][ft_strlen(array[i]) - 1] == '\n')
			array[i][ft_strlen(array[i]) - 1] = '\0';
	}
}

void	free_textures_line(char *textures_line[4])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (textures_line[i])
			free(textures_line[i]);
	}
}

int	open_texture(t_data *data, char *textures_line[4])
{
	data->map.walls_text[NORTH].image
		= mlx_xpm_file_to_image(data->mlx,
			textures_line[NORTH], &data->map.walls_text[NORTH].width,
			&data->map.walls_text[NORTH].height);
	if (!data->map.walls_text[NORTH].image)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_NORTH"\n"), ERC_TEXTURE);
	data->map.walls_text[SOUTH].image
		= mlx_xpm_file_to_image(data->mlx,
			textures_line[SOUTH], &data->map.walls_text[SOUTH].width,
			&data->map.walls_text[SOUTH].height);
	if (!data->map.walls_text[SOUTH].image)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_SOUTH"\n"), ERC_TEXTURE);
	data->map.walls_text[EAST].image
		= mlx_xpm_file_to_image(data->mlx,
			textures_line[EAST], &data->map.walls_text[EAST].width,
			&data->map.walls_text[EAST].height);
	if (!data->map.walls_text[EAST].image)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_EAST"\n"), ERC_TEXTURE);
	data->map.walls_text[WEST].image
		= mlx_xpm_file_to_image(data->mlx,
			textures_line[WEST], &data->map.walls_text[WEST].width,
			&data->map.walls_text[WEST].height);
	if (!data->map.walls_text[WEST].image)
		return (ft_dprintf(STDERR_FILENO, ERM_TEXTURE_WEST"\n"), ERC_TEXTURE);
	return (EXIT_SUCCESS);
}
