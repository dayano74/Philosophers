/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:34:42 by dayano            #+#    #+#             */
/*   Updated: 2025/05/26 02:51:24 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_data		*data;
}	t_philo;

typedef struct s_data
{
	int					philo_count;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					required_meals;
	long				start_time;
	int					is_simulation_end;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_t			monitor_thread;
	t_philo				*philos;
}	t_data;

int		parse_args(int argc, char **argv);
int		init_philosophers(void);
int		create_threads(void);
void	wait_for_threads(void);
void	cleanup_resources(void);

long	get_timestamp(void);
void	print_status(t_philo *philo, char *status);

#endif
