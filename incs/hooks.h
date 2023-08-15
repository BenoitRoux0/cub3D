/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:42:19 by beroux            #+#    #+#             */
/*   Updated: 2023/08/15 09:54:49 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub.h"
# include <X11/X.h>

int	on_destroy(t_data *data);
int on_key_press(int keycode, t_data *data);

#endif