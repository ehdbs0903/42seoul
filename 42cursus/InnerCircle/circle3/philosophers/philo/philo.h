/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doykim   <doykim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:46:15 by doykim            #+#    #+#             */
/*   Updated: 2022/12/19 20:00:06 by doykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long long		start_time;
	int				all_alive;
	pthread_mutex_t	*forks;
	pthread_mutex_t	guard;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_t		thread;
	pthread_mutex_t	guard;
	int				left_fork;
	int				right_fork;
	long long		eat_time;
	int				eat_count;
	int				finish;
}	t_philo;

void		start_philo_process(t_philo **philo, t_info *info);
void		*one_routine(void *arg);
void		*routine(void *arg);

int			philo_atoi(const char *str);
int			init_info(t_info *info, int argc, char **argv);
int			check_info_value(t_info *info, int argc);
int			init_philo(t_philo **philo, t_info *info);
void		free_info_malloc(t_info *info);

void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

void		monitoring(t_philo **philo, t_info *info);
void		check_philo_die(t_philo *philo, t_info *info);
int			check_all_alive(t_info *info);

void		print_status(t_philo *philo, char *str);
long long	get_time(void);
int			return_error(char *str);

void		free_all(t_philo **philo, t_info *info);

#endif
