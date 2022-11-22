/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim <doykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:16:14 by doykim            #+#    #+#             */
/*   Updated: 2022/11/22 16:16:16 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_number;
	int				eat;
	pthread_mutex_t	is_dead;
	size_t			time;
	pthread_mutex_t	print;
}	t_args;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	size_t			should_die;
	int				eat_max;
	t_args			*args;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
}	t_philo;

/***************** Src part ***************************/

int		ft_isdigit(int c);
int		ft_isnumber(char *number);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

/******************* Mandatory part ***********************/

t_philo	*create_philo(t_args *args);
void	mutex_print(int id, t_args *args, char *message);
void	*checke_if_dead(void *philo);
t_philo	*philo_init(t_args *args);
size_t	get_current_time(void);
void	routine(t_philo *philosopher, t_args *args);
int		ft_isnumber(char *number);
int		args_init(int argc, char **argv, t_args *args);
void	routine(t_philo *philo, t_args *args);
void	*philosophers(void *philo);
void	philo_init_utils(t_args *args, t_philo *philo, int i);

#endif
