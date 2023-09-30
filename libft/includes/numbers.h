/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:29:39 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/29 15:39:42 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H
# include <limits.h>
# include <stdlib.h>
# include <errno.h>
# include "char.h"

int		ft_atoi(const char *str);
float	ft_atof(const char *str);
char	*ft_itoa(int n);
#endif
