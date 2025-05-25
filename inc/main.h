/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:34:42 by dayano            #+#    #+#             */
/*   Updated: 2025/05/26 03:13:35 by dayano           ###   ########.fr       */
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
# include "struct.h"

// parse.c
int		parse_args(int argc, char **argv);
int		init_philosophers(void);
int		create_threads(void);
void	wait_for_threads(void);
void	cleanup_resources(void);

// utils.c
int		ft_atoi(const char *str);
int		is_valid_number(const char *str);

long	get_timestamp(void);
void	print_status(t_philo *philo, char *status);

#endif
