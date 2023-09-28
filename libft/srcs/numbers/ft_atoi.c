/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:41:46 by gd-harco          #+#    #+#             */
/*   Updated: 2023/09/28 15:07:38 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"

static int	ft_overflow(int sign)
{
	if (sign < 0)
		return ((int)LONG_MIN);
	else
		return ((int)LONG_MAX);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (errno = 20, 0);
	while (ft_isdigit(*str))
	{
		if (result != (result * 10 + *str - '0') / 10)
			return (errno = 21, ft_overflow(sign));
		result = (result * 10) + (*str - '0');
		str++;
	}
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (errno = 20, 0);
		str++;
	}
	return ((int)result * sign);
}
