/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:34:42 by dayano            #+#    #+#             */
/*   Updated: 2025/06/05 18:36:11 by dayano           ###   ########.fr       */
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
# include <limits.h>
# include "struct.h"

// parse.c
int		parse_args(int argc, char **argv, t_data *data);

// philo.c
int		init_mutex_and_philo(t_data *data);

// thread.c
int		create_threads(t_data *data);
void	wait_for_threads(t_data *data);

// actions.c
void	eat(t_philo *philo);
void	sleep_philosopher(t_philo *philo);
void	think(t_philo *philo);

// utils.c
long	get_timestamp(void);
void	print_status(t_philo *philo, char *status);
int		is_simulation_ended(t_data *data);
void	cleanup_resources(t_data *data);

// str_utils.c
long	ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif
