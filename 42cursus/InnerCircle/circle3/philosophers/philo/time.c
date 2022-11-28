/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:07:36 by doykim            #+#    #+#             */
/*   Updated: 2022/11/28 16:55:30 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)wait_time)
		usleep(100);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	t_time				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
