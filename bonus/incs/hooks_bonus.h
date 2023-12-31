/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:42:19 by beroux            #+#    #+#             */
/*   Updated: 2023/10/04 16:42:09 by gd-harco         ###   ########.fr       */
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
int	on_mouse_clic(int button, int x, int y, t_data *data);
int	on_mouvement(int x, int y, t_data *data);
int	on_focus_in(t_data *data);
int	on_focus_out(t_data *data);

#endif
