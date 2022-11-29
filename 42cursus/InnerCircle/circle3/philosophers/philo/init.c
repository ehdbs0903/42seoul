/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:16:20 by doykim            #+#    #+#             */
/*   Updated: 2022/11/29 15:27:50 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_philo *philo, int num, int num_of_philos)
{
	int	i;

	i = num;
	while (i < num_of_philos)
	{
		philo[i].philo_number = i;
		pthread_create(&philo[i].philo_tid, NULL, thread_philo, &philo[i]);
		i += 2;
	}
}

void	init_varialbe(int ac, char **av, t_variable *variable)
{
	if (ac == 5)
		variable->must_eat = -1;
	else
		variable->must_eat = ft_atoi(av[5]);
	variable->num_of_philos = ft_atoi(av[1]);
	variable->time_to_die = ft_atoi(av[2]);
	variable->time_to_eat = ft_atoi(av[3]);
	variable->time_to_sleep = ft_atoi(av[4]);
	variable->finished_meal = 0;
	variable->philo_alive = 1;
	variable->first_meal_time.tv_sec = 0;
	variable->first_meal_time.tv_usec = 0;
}

void	init_mutex(t_mutex *mutex, t_variable *variable)
{
	int	i;

	i = -1;
	mutex->mutex_forks = malloc(sizeof(pthread_mutex_t) * \
		variable->num_of_philos);
	if (mutex->mutex_forks == NULL)
		print_error(2);
	while (++i < variable->num_of_philos)
		pthread_mutex_init(&mutex->mutex_forks[i], NULL);
	pthread_mutex_init(&mutex->mutex_print, NULL);
}

t_philo	*init_philos(t_variable *variable, t_mutex *mutex)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * variable->num_of_philos);
	if (philo == NULL)
		print_error(2);
	while (++i < variable->num_of_philos)
	{
		philo[i].mutex = mutex;
		philo[i].variable = variable;
		philo[i].have_meal = 0;
		philo[i].last_meal_time = 0;
		philo[i].fork_number[RIGHT] = i;
		philo[i].fork_number[LEFT] = -1;
		if (i + 1 != variable->num_of_philos)
			philo[i].fork_number[LEFT] = i + 1;
		else if (i != 0)
			philo[i].fork_number[LEFT] = 0;
	}
	return (philo);
}
