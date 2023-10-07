/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:43:22 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/01 15:28:36 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	compare_timeval(struct timeval *current_time, struct timeval *goal_time)
{
	if (current_time->tv_sec < goal_time->tv_sec)
		return (-1);
	if (current_time->tv_sec > goal_time->tv_sec)
		return (1);
	if (current_time->tv_usec < goal_time->tv_usec)
		return (-1);
	if (current_time->tv_usec > goal_time->tv_usec)
		return (1);
	return (0);
}

void	add_ms_tv(struct timeval *tv, long milliseconds)
{
	tv->tv_sec += milliseconds / 1000;
	milliseconds %= 1000;
	tv->tv_usec += milliseconds * 1000;
	if (tv->tv_usec >= 1000000)
	{
		tv->tv_sec += tv->tv_usec / 1000000;
		tv->tv_usec %= 1000000;
	}
}

int	msleep(int ms_to_sleep)
{
	struct timeval	goal_time;
	struct timeval	current_time;

	gettimeofday(&goal_time, NULL);
	add_ms_tv(&goal_time, ms_to_sleep);
	while (42)
	{
		gettimeofday(&current_time, NULL);
		if (compare_timeval(&current_time, &goal_time) >= 0)
			return (0);
		usleep(10);
	}
	return (0);
}
