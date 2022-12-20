/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim   <doykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:05 by doykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:54:46 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (return_error("argument error"));
	if (!(init_info(&info, argc, argv)))
		return (0);
	if (!(init_philo(&philo, &info)))
		return (0);
	start_philo_process(&philo, &info);
	free_all(&philo, &info);
	return (0);
}

void	start_philo_process(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	if (info->num_of_philo == 1)
	{
		pthread_create(&((*philo)[i].thread), NULL, \
			one_routine, &((*philo)[i]));
		pthread_join((*philo)[i].thread, NULL);
		return ;
	}
	while (i < info->num_of_philo)
	{
		pthread_create(&((*philo)[i].thread), NULL, routine, &((*philo)[i]));
		i++;
	}
	monitoring(philo, info);
}

void	*one_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(philo->info->time_to_die * 1000);
	printf("%lld %d is died\n", \
		get_time() - philo->info->start_time, 1);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat);
	while (check_all_alive(philo->info))
	{
		philo_eat(philo);
		(philo->eat_count)++;
		if (philo->eat_count == philo->info->must_eat_count)
		{
			pthread_mutex_lock(&(philo->guard));
			philo->finish = 1;
			pthread_mutex_unlock(&(philo->guard));
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
