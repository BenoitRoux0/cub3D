/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:42:31 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/09 12:49:57 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_BONUS_H
# define WEAPON_BONUS_H

# include "cub_bonus.h"

void	open_weapon_sprites(t_data *data);
void	clear_weapon(t_uint_img *fallback, t_weapon *weapon);
int		render_weapon(t_data *data);

# define NB_OF_FRAME 15

#endif
