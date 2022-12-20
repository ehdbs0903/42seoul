/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:49:27 by doykim            #+#    #+#             */
/*   Updated: 2022/12/19 19:52:01 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join((*philo)[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		pthread_mutex_destroy(&((*philo)[i].guard));
		i++;
	}
	pthread_mutex_destroy(&(info->guard));
	pthread_mutex_destroy(&(info->print));
	free(info->forks);
	free(*philo);
}
