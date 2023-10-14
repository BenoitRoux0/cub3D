/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:44:16 by beroux            #+#    #+#             */
/*   Updated: 2023/10/12 16:55:48 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOORS_BONUS_H
# define DOORS_BONUS_H

# include "cub_bonus.h"

void		destroy_doors_map(t_doors_map doors_map);
t_doors_map	create_doors_map(t_map map);

#endif