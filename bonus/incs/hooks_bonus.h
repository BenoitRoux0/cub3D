/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:42:19 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 17:22:55 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include "cub_bonus.h"

//-----------------FUNCTION-----------------//
int	on_destroy(t_data *data);
int	on_key_press(int keycode, t_data *data);
int	on_key_released(int keycode, t_data *data);
int	on_loop(t_data *data);
int	on_mouse(int button, int x, int y, t_data *data);
#endif
