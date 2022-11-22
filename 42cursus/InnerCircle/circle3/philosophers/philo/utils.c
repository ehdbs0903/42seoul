/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:17:25 by doykim            #+#    #+#             */
/*   Updated: 2022/11/22 16:17:27 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_print(int id, t_args *args, char *message)
{
	pthread_mutex_lock(&args->print);
	printf("\033[0;36mMs : %lu \e[0m| Philo Id: [%d] \033[0;33m%s\033[0m\n",
		get_current_time() - args->time, id, message);
	pthread_mutex_unlock(&args->print);
}

void	*checke_if_dead(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	while (1)
	{
		if (get_current_time() >= philosopher->should_die + 5)
		{
			mutex_print(philosopher->philo_id, philosopher->args,
				"philosopher is dead");
			pthread_mutex_lock(&philosopher->args->print);
			pthread_mutex_unlock(&philosopher->args->is_dead);
		}
		else if (philosopher->eat_max == 1)
		{
			pthread_mutex_lock(&philosopher->args->print);
			pthread_mutex_unlock(&philosopher->args->is_dead);
		}
	}
	return (NULL);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	philo_init_utils(t_args *args, t_philo *philo, int i)
{
	pthread_mutex_init(&philo[i].fork, NULL);
	philo[i].philo_id = i + 1;
	philo[i].args = args;
	if (i == args->philo_number - 1)
		philo[i].next_fork = &philo[0].fork;
	else
		philo[i].next_fork = &philo[i + 1].fork;
}
