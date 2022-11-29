/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:28:36 by doykim            #+#    #+#             */
/*   Updated: 2022/11/29 16:13:10 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ret_timestamp(t_philo *philo)
{
	struct timeval	get_time;
	struct timeval	first_meal;
	int				timestamp;

	first_meal = philo->variable->first_meal_time;
	if (first_meal.tv_sec == 0)
		return (0);
	gettimeofday(&get_time, NULL);
	timestamp = (get_time.tv_sec * 1000000 + get_time.tv_usec) - \
		(first_meal.tv_sec * 1000000 + first_meal.tv_usec);
	return (timestamp);
}

int	print_status(t_philo *philo, char *str, int status, int philo_number)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	if (status != STATUS_END && philo->variable->philo_alive == 0)
		return (RET_DEAD);
	timestamp = ret_timestamp(philo);
	printf("%d %d %s\n", timestamp / 1000, philo_number, str);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	if (status == STATUS_EAT)
	{
		philo->last_meal_time = timestamp;
		ft_usleep(philo, philo->variable->time_to_eat, timestamp);
	}
	if (status == STATUS_SLEEP)
		ft_usleep(philo, philo->variable->time_to_sleep, timestamp);
	return (0);
}

int	sleep_until_even_eat(t_variable variable)
{
	struct timeval	get_time;
	struct timeval	timestamp;
	int				time_taken;

	gettimeofday(&get_time, NULL);
	while (1)
	{
		gettimeofday(&timestamp, NULL);
		time_taken = timestamp.tv_usec - get_time.tv_usec + \
			(timestamp.tv_sec - get_time.tv_sec) * 1000000;
		if (time_taken > variable.time_to_eat * 900)
			break ;
		usleep(variable.time_to_eat);
	}
	return (0);
}

static int	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[LEFT]]) != 0)
		return (-1);
	if (print_status(philo, "has taken a fork", STATUS_FORK, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]) != 0)
		return (-1);
	if (print_status(philo, "has taken a fork", STATUS_FORK, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
	if (print_status(philo, "is eating", STATUS_EAT, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[LEFT]]);
	philo->have_meal++;
	if (philo->have_meal == philo->variable->must_eat)
		philo->variable->finished_meal++;
	return (0);
}

void	*thread_philo(void *start_routine)
{
	t_philo	*philo;

	philo = (t_philo *)start_routine;
	if (philo->variable->first_meal_time.tv_sec == 0)
		gettimeofday(&philo->variable->first_meal_time, NULL);
	while (philo->variable->philo_alive == 1)
	{
		if (philo_eat(philo) != 0)
			break ;
		if (print_status(philo, "is sleeping", STATUS_SLEEP, \
			philo->philo_number + 1) != 0)
			break ;
		if (print_status(philo, "is thinking", STATUS_THINK, \
			philo->philo_number + 1) != 0)
			break ;
	}
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[LEFT]]);
	return (0);
}
