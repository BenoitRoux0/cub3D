/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:16:35 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/11 18:05:23 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	open_sprite(t_data *data, char *buff);
static void	open_door(t_data *data, char *buff);
static void	init_default(t_sprite *sprite);

void	get_sprites(int fd, t_data *data)
{
	char	*buff;
	char	*pre_buff;

	pre_buff = get_next_line(fd);
	if (!pre_buff)
		parse_error_quit(data, STRANGE_CODE);
	buff = ft_strtrim(pre_buff, " ");
	free(pre_buff);
	while (buff)
	{
		if (buff[0] >= 'a' && buff[0] <= 'z')
			open_sprite(data, buff);
		else if (buff[0] == 'D')
			open_door(data, buff);
		free(buff);
		pre_buff = get_next_line(fd);
		if (!pre_buff)
			break ;
		if (pre_buff[0] != '\n')
			buff = ft_strtrim(pre_buff, " ");
		else
			buff = ft_strdup(pre_buff);
		free(pre_buff);
	}
	set_fallback_sprite(data);
	return ;
}

void	open_sprite(t_data *data, char *buff)
{
	char	**sprite_line;
	int		char_pos;
	int		r;

	char_pos = buff[0] - 'a';
	sprite_line = ft_split(&buff[1], ' ');
	if (!sprite_line)
		parse_error_quit(data, STRANGE_CODE);
	init_default(&data->map.sprites[char_pos]);
	r = set_sprite(data, &data->map.sprites[char_pos], sprite_line);
	ft_free_split(sprite_line);
	if (r == EXIT_FAILURE)
	{
		free(buff);
		parse_error_quit(data, STRANGE_CODE);
	}
}

void	init_default(t_sprite *sprite)
{
	sprite->height = 0.5;
	sprite->x_pos = 0.5;
	sprite->y_pos = 0.5;
}

//TODO Open Door function
