/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:00:22 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 15:47:42 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "cub_bonus.h"

// -----------------FUNCTION-----------------//
t_player	init_player(enum e_dir dir, t_vec_2i pos);
int			key_press_player(int key_code, t_data *data);
int			key_released_player(int key_code, t_data *data);
int			update_player(t_data *data);

#endif
