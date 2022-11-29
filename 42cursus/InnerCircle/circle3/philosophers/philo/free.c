/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:43:25 by doykim            #+#    #+#             */
/*   Updated: 2022/11/29 13:26:48 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, t_mutex *mutex, t_variable *variable)
{
	int	i;

	i = -1;
	while (++i < variable->num_of_philos)
		pthread_join(philo[i].philo_tid, NULL);
	i = -1;
	pthread_mutex_destroy(&mutex->mutex_print);
	while (++i < variable->num_of_philos)
		pthread_mutex_destroy(&mutex->mutex_forks[i]);
	free(mutex->mutex_forks);
	free(philo);
}
