/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:42:13 by beroux            #+#    #+#             */
/*   Updated: 2023/09/03 02:47:26 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ANTI_ALIASING 0
# define NB_RAYS (WIN_WIDTH << ANTI_ALIASING)

# define CELL_SIZE 64
# define INTER_LIM 512

# define PLAYER_SPEED 3
# define PLAYER_FOV 60

#endif