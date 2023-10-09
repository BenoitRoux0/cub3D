/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:27:30 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 11:31:21 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	clear_weapon(t_uint_img *fallback, t_weapon *weapon)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		if (weapon->weapon_img[i] != fallback)
			clear_img(weapon->weapon_img[i]);
	}
}
