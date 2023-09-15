/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:42:19 by beroux            #+#    #+#             */
/*   Updated: 2023/09/15 15:47:42 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub_bonus.h"

//-----------------FUNCTION-----------------//
int	on_destroy(t_data *data);
int	on_key_press(int keycode, t_data *data);
int	on_key_released(int keycode, t_data *data);
int on_loop(t_data *data);

#endif
