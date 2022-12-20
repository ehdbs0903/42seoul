/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim   <doykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:57:03 by doykim            #+#    #+#             */
/*   Updated: 2022/12/19 19:53:48 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(const char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while ((9 <= str[i] && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			if (res > 2147483647)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return ((int)res);
}

int	init_info(t_info *info, int argc, char **argv)
{
	int	i;

	info->num_of_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		info->must_eat_count = philo_atoi(argv[5]);
	else
		info->must_eat_count = -1;
	if (!(check_info_value(info, argc)))
		return (return_error("argument error"));
	info->all_alive = 1;
	info->forks = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!(info->forks))
		return (return_error("malloc error"));
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_init(&(info->forks[i]), NULL);
	pthread_mutex_init(&(info->guard), NULL);
	pthread_mutex_init(&(info->print), NULL);
	return (1);
}

int	check_info_value(t_info *info, int argc)
{
	if (info->num_of_philo <= 0 || \
		info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || \
		info->time_to_sleep <= 0 || \
		((argc == 6) && (info->must_eat_count <= 0)))
		return (0);
	else
		return (1);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!(*philo))
	{
		free_info_malloc(info);
		return (return_error("argument error"));
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].id = i + 1;
		pthread_mutex_init(&((*philo)[i].guard), NULL);
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % info->num_of_philo;
		(*philo)[i].eat_time = get_time();
		(*philo)[i].eat_count = 0;
		(*philo)[i].finish = 0;
		i++;
	}
	return (1);
}

void	free_info_malloc(t_info *info)
{
	int	i;

	i = 0;
	while (info->num_of_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	free(info->forks);
	pthread_mutex_destroy(&(info->guard));
	pthread_mutex_destroy(&(info->print));
}
