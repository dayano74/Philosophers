/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:53:09 by dayano            #+#    #+#             */
/*   Updated: 2025/06/05 18:10:36 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long	get_timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status)
{
	long timestamp;
	int is_end;

	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	is_end = philo->data->is_simulation_end;
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (!is_end || !strcmp(status, "died"))
	{
		timestamp = get_timestamp() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int is_simulation_ended(t_data *data)
{
	int ret;

	pthread_mutex_lock(&data->death_mutex);
	ret = data->is_simulation_end;
	pthread_mutex_unlock(&data->death_mutex);
	return (ret);
}

void	cleanup_resources(t_data *data)
{
	int i;

	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}
