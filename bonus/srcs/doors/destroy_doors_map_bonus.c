/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_doors_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:40:59 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 16:54:52 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	destroy_doors_map(t_doors_map doors_map)
{
	int	i;

	if (!doors_map.content)
		return ;
	i = 0;
	while (i < doors_map.size[1] && doors_map.content[i])
	{
		free(doors_map.content[i]);
		i++;
	}
	free(doors_map.content);
}
