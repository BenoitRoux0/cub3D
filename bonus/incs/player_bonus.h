/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:00:22 by beroux            #+#    #+#             */
/*   Updated: 2023/09/26 18:31:03 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// -----------------FUNCTION-----------------//
t_player	init_player(enum e_dir dir, t_vec_2i pos);
int			key_press_player(int key_code, t_data *data);
int			key_released_player(int key_code, t_data *data);
int			update_player(t_data *data);
void		collide(t_data *data, double pos[2], double next_pos[2]);
int			js_button_press_player(int key_code, void *data);
int			js_button_released_player(int key_code, void *data);
int			js_joystick_moved_player(int key_code, int16_t value, void *data);

#endif
