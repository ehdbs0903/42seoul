/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:16:20 by doykim            #+#    #+#             */
/*   Updated: 2022/11/28 18:53:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philo *philo, int argc, char **argv)
{
	int	is_dead;
	int	i;

	i = 0;
	is_dead = 0;
	while (i < ft_atol(argv[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atol(argv[2]);
		philo[i].time_to_eat = ft_atol(argv[3]);
		philo[i].time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atol(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].meals_eaten = 0;
		philo[i].philo_nb = ft_atol(argv[1]);
		philo[i].is_dead = &is_dead;
		i++;
	}
	philo->total_eaten = 0;
}

void	ft_init_mutex(t_philo *philo, char **argv,
	pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		philo[i].left_fork_mutex = &forks[i];
		philo[i].right_fork_mutex = &forks[(i + 1) % philo->philo_nb];
		i++;
	}
	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}
