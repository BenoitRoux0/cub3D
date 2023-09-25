/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gamepads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:50:44 by beroux            #+#    #+#             */
/*   Updated: 2023/09/25 16:04:40 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamepad.h"

static void				check_disconnections(t_gamepad *gamepads);
static struct dirent	*get_next_controller(char *dir_path, DIR *dir);
static int				check_node(char *dir_path, struct dirent *node);
static bool				is_in_gamepads(ino_t inode, t_gamepad *gamepads);

int	update_gamepads(t_gamepad *gamepads)
{
	struct dirent	*next;
	t_gamepad		*tmp;
	DIR				*events_dir;

	tmp = gamepads;
	check_disconnections(gamepads);
	events_dir = opendir("/dev/input/");
	next = get_next_controller("/dev/input/", events_dir);
	while (tmp && tmp->connected)
		tmp = tmp->next;
	while (next && tmp && is_in_gamepads(next->d_ino, gamepads) == false)
	{
		tmp->name = ft_strjoin("/dev/input/", next->d_name);
		tmp->fd = open(tmp->name, O_RDONLY | O_NONBLOCK);
		tmp->connected = true;
		tmp->inode = next->d_ino;
		next = get_next_controller("/dev/input/", events_dir);
		while (tmp && tmp->connected)
			tmp = tmp->next;
	}
	closedir(events_dir);
	return (0);
}

static void	check_disconnections(t_gamepad *gamepads)
{
	struct stat	statbuff;

	if (!gamepads)
		return ;
	if (gamepads->connected && stat(gamepads->name, &statbuff))
	{
		free(gamepads->name);
		gamepads->name = NULL;
		gamepads->connected = false;
		gamepads->fd = -1;
	}
	if (gamepads->next)
		check_disconnections(gamepads->next);
}

static struct dirent	*get_next_controller(char *dir_path, DIR *dir)
{
	struct dirent	*current_node;

	current_node = readdir(dir);
	while (current_node && !check_node(dir_path, current_node))
		current_node = readdir(dir);
	return (current_node);
}

static int	check_node(char *dir_path, struct dirent *node)
{
	char	*full_path;
	int		fd;
	int		driver_version;

	full_path = ft_strjoin(dir_path, node->d_name);
	if (!full_path)
		return (0);
	fd = open(full_path, O_RDONLY | O_NONBLOCK);
	if (fd < 0)
		return (free(full_path), 0);
	if (ioctl(fd, JSIOCGVERSION, &driver_version) == -1)
		return (free(full_path), close(fd), 0);
	return (free(full_path), close(fd), 1);
}

static bool	is_in_gamepads(ino_t inode, t_gamepad *gamepads)
{
	t_gamepad	*tmp;

	tmp = gamepads;
	while (tmp)
	{
		if (tmp->inode == inode)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
