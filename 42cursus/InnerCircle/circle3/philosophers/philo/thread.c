/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykimy@student.42.kr>              +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:05:47 by doykim            #+#    #+#             */
/*   Updated: 2022/11/28 18:38:28 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, &philo[i]);
		i++;
		usleep(100);
	}
	while (*philo->is_dead != 1)
		ft_check_death(philo);
}
