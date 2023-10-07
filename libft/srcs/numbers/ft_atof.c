/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:38:12 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/01 15:49:44 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include "char.h"
#include "str.h"

bool	is_negative(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (true);
	}
	return (false);
}

int	get_both_commas(const char *str, int *pre, int *post)
{
	char	*pre_str;
	char	*post_str;
	int		i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (ft_strchr(&str[i + 1], '.') != NULL)
		return (errno = 20);
	if (str[i] == '\0')
		return (*pre = ft_atoi(str));
	pre_str = ft_substr(str, 0, i);
	post_str = ft_substr(str, i + 1, ft_strlen(str) - i);
	*pre = ft_atoi(pre_str);
	*post = ft_atoi(post_str);
	free(pre_str);
	free(post_str);
	return (0);
}

float	ft_atof(const char *str)
{
	float	result;
	int		sign;
	int		pre_comma;
	int		post_comma;

	pre_comma = 0;
	post_comma = 0;
	result = 0;
	get_both_commas(str, &pre_comma, &post_comma);
	if (errno == 20)
		return (0);
	if (is_negative (&pre_comma))
		sign = -1;
	else
		sign = 1;
	while (post_comma > 0)
	{
		result += post_comma % 10;
		result /= 10;
		post_comma /= 10;
	}
	result += pre_comma;
	return (result * sign);
}
