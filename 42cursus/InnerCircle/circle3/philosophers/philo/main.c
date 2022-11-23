/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:15:01 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/12 02:36:22 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(int n)
{
	if (n == 1)
	{
		printf("arg_error");
		exit(1);
	}
	if (n == 2)
	{
		printf("malloc_error");		
	}
}

static int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (argc < 5 || argc > 6)
		print_error(1);
	if (ft_check_args(argc, argv) == 0)
		print_error(1);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo)
		print_error(2);
	ft_init_philos(philo, argc, argv);
	ft_init_mutex(philo, argv, forks, death);
	ft_join_threads(philo, argv);
	ft_free(philo, forks, death);
	return (0);
}
