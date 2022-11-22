/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:15:48 by doykim            #+#    #+#             */
/*   Updated: 2022/11/22 16:15:51 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_handling(int ac)
{
	if (ac < 4)
	{
		ft_putstr_fd("\e[1;91mError: Too few arguments\e[0m", 2);
		return (1);
	}
	else if (ac > 5)
	{
		ft_putstr_fd("\e[1;91mError: Too many arguments\e[0m", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_args	args;
	int		index;

	philo = NULL;
	index = 0;
	args.eat = 0;
	if (error_handling(--ac) || args_init(ac, av, &args))
		return (1);
	pthread_mutex_init(&args.is_dead, NULL);
	pthread_mutex_init(&args.print, NULL);
	pthread_mutex_lock(&args.is_dead);
	philo = philo_init(&args);
	if (!philo)
		return (1);
	pthread_mutex_lock(&args.is_dead);
	while (index < args.philo_number)
		pthread_mutex_destroy(&philo[index++].fork);
	pthread_mutex_destroy(&args.print);
	free(philo);
	return (0);
}
