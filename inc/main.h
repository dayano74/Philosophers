/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:34:42 by dayano            #+#    #+#             */
/*   Updated: 2025/05/26 03:39:33 by dayano           ###   ########.fr       */
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
# include "utils.h"
# include "philo.h"

// parse.c
int		parse_args(int argc, char **argv, t_data *data);
int		create_threads(t_data *data);
void	wait_for_threads(t_data *data);
void	cleanup_resources(t_data *data);

long	get_timestamp(void);
void	print_status(t_philo *philo, char *status);

#endif
