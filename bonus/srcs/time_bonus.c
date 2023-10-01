/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:09:32 by gd-harco          #+#    #+#             */
/*   Updated: 2023/10/01 15:09:32 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:43:22 by gd-harco          #+#    #+#             */
/*   Updated: 2023/07/21 14:43:25 by gd-harco         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	compare_timeval(struct timeval *t1, struct timeval *t2)
{
	if (t1->tv_sec < t2->tv_sec)
		return (-1);
	if (t1->tv_sec > t2->tv_sec)
		return (1);
	if (t1->tv_usec < t2->tv_usec)
		return (-1);
	if (t1->tv_usec > t2->tv_usec)
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

int	msleep(t_ms ms_to_sleep, t_philo *philo)
{
	struct timeval	goal_time;
	struct timeval	current_time;

	(void)philo;
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
