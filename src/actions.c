/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:54:09 by dayano            #+#    #+#             */
/*   Updated: 2025/06/05 20:28:02 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	precise_sleep(long milliseconds, t_data *data)
{
	long	start_time;
	long	elapsed_time;

	start_time = get_timestamp();
	while (!is_simulation_ended(data))
	{
		elapsed_time = get_timestamp() - start_time;
		if (elapsed_time >= milliseconds)
			break ;
		usleep(100);
	}
}

void	_philo_count_is_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	precise_sleep(philo->data->time_to_die + 10, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	return ;
}

void	eat(t_philo *philo)
{
	if (philo->data->philo_count == 1)
		return (_philo_count_is_one(philo));
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	precise_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_philosopher(t_philo *philo)
{
	print_status(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep, philo->data);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
	usleep(100);
}
