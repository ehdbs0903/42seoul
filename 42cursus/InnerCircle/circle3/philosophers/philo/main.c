/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:15:01 by doykim            #+#    #+#             */
/*   Updated: 2022/11/29 16:12:58 by doykim           ###   ########.fr       */
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
		exit(1);
	}
}

static int	check_args(int argc, char **argv)
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

static void	check_end_conditions(t_philo *philo, t_variable *variable)
{
	int	timestamp;
	int	i;

	i = -1;
	while (++i < variable->num_of_philos)
	{
		timestamp = ret_timestamp(philo);
		if ((timestamp - philo[i].last_meal_time) / 1000 >= \
			variable->time_to_die)
		{
			variable->philo_alive = 0;
			print_status(philo, "died", STATUS_END, i + 1);
			break ;
		}
		else if (variable->finished_meal == variable->num_of_philos)
		{
			variable->philo_alive = 0;
			print_status(philo, "End of meal", STATUS_END, i + 1);
			break ;
		}
		if (i == variable->num_of_philos - 1)
			i = -1;
	}
	free_all(philo, philo->mutex, philo->variable);
}

static void	sleep_until_even_eat(t_variable variable)
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
		if (time_taken > variable.time_to_eat * 1000)
			break ;
		usleep(variable.time_to_eat);
	}
}

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	t_variable		variable;
	t_mutex			mutex;

	i = -1;
	if (ac != 5 && ac != 6)
		print_error(1);
	if (check_args(ac, av) == 0)
		print_error(1);
	init_varialbe(ac, av, &variable);
	init_mutex(&mutex, &variable);
	philo = init_philos(&variable, &mutex);
	//짝
	create_thread(philo, 1, variable.num_of_philos);
	sleep_until_even_eat(variable);
	create_thread(philo, 0, variable.num_of_philos);
	check_end_conditions(philo, &variable);
	return (0);
}
