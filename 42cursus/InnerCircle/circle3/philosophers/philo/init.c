/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:17:01 by doykim            #+#    #+#             */
/*   Updated: 2022/11/22 16:17:03 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (!number)
		return (1);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	args_init(int argc, char **argv, t_args *args)
{
	if (!ft_isnumber(argv[1]) || !ft_isnumber(argv[2]) || !ft_isnumber(argv[3])
		|| !ft_isnumber(argv[4]) || !ft_isnumber(argv[5]))
		return (ft_putstr_fd("\e[1;91mError: Invalid Arguments\e[0m\n", 2), 1);
	args->philo_number = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		args->eating_number = ft_atoi(argv[5]);
	if (args->philo_number <= 0 || args->time_to_die <= 59
		|| args->time_to_eat <= 59 || args->time_to_sleep <= 59
		|| args->eating_number <= 0)
		return (printf("\e[1;91mError: Wrong Arguments\e[0m\n"), 1);
	if (argc < 5)
			args->eating_number = 0;
	return (0);
}

void	routine(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&philo->fork);
	mutex_print(philo->philo_id, args, "take a fork");
	pthread_mutex_lock(philo->next_fork);
	mutex_print(philo->philo_id, args, "take second fork");
	philo->should_die = get_current_time() + philo->args->time_to_die;
	mutex_print(philo->philo_id, args, "is eating");
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philo -> fork);
	pthread_mutex_unlock(philo -> next_fork);
	mutex_print(philo->philo_id, args, "is sleeping");
	usleep(philo->args->time_to_sleep * 1000);
	mutex_print(philo->philo_id, args, "is thinking...");
}

void	*philosophers(void *philo)
{
	int			i;
	t_philo		*philosopher;
	pthread_t	thread_id;

	i = 0;
	philosopher = (t_philo *)philo;
	philosopher->eat_max = 0;
	philosopher->should_die = philosopher->args->time
		+ philosopher->args->time_to_die;
	pthread_create(&thread_id, NULL, &checke_if_dead, philosopher);
	pthread_detach(thread_id);
	while (i < philosopher->args->eating_number
		|| !(philosopher->args->eating_number))
	{
		routine(philosopher, philosopher->args);
		i++;
		if (i == philosopher->args->eating_number)
		{
			philosopher->args->eat += 1;
			mutex_print(philosopher->philo_id,
				philosopher->args, "is thinking...");
		}
	}
	philosopher->eat_max = 1;
	return (NULL);
}

t_philo	*philo_init(t_args *args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * args ->philo_number);
	if (!philo)
		return (printf("Error: Allocation failed"), NULL);
	args->time = get_current_time();
	args->eat = 0;
	while (i < args->philo_number)
	{
		philo_init_utils(args, philo, i);
		if (pthread_create(&philo[i].thread_id, NULL, &philosophers, &philo[i]))
			return (free(philo), printf("Error occured thread creation"), NULL);
		usleep(10);
		i++;
	}
	i = 0;
	while (i < args ->philo_number)
		pthread_detach(philo[i++].thread_id);
	return (philo);
}
