/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:35:56 by dayano            #+#    #+#             */
/*   Updated: 2025/05/27 22:02:08 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0 ||
		pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		cleanup_mutexes(data);
		return (1);
	}
	return (0);
}

int		init_mutex_and_philo(t_data *data)
{
	if (init_mutexes(data) != 0)
		return (1);
	if (init_philos(data) != 0)
	{
		cleanup_mutexes(data);
		return (1);
	}
}
