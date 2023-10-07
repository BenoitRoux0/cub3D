/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:42:13 by beroux            #+#    #+#             */
/*   Updated: 2023/10/04 16:02:22 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# ifndef WIN_WIDTH
#  define WIN_WIDTH 720
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 480
# endif

# define CELL_SIZE 512
# define CELL_SH 9
# define INTER_LIM 512

# define PLAYER_SPEED 25
# define PLAYER_ROT_SPEED 2
# define PLAYER_FOV 60

# define FALLBACK_WALL "./textures/error_wall.xpm"
# define FALLBACK_SPRITE "./textures/error_sprite.xpm"

#endif
