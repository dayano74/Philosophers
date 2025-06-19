/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:51:16 by dayano            #+#    #+#             */
/*   Updated: 2025/06/19 20:46:43 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	int		should_exit;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&philo->data->death_mutex);
	if (philo->id % 2 == 0)
		usleep(1000);
	should_exit = 0;
	while (!is_simulation_ended(philo->data) && !should_exit)
	{
		eat(philo);
		if (philo->data->required_meals > 0
			&& philo->meals_eaten >= philo->data->required_meals)
			should_exit = 1;
		if (!is_simulation_ended(philo->data))
			sleep_philosopher(philo);
		if (!is_simulation_ended(philo->data))
			think(philo);
	}
	return (NULL);
}

static int	check_if_died(t_philo *philo)
{
	long	cur_time;

	pthread_mutex_lock(&philo->data->death_mutex);
	cur_time = get_timestamp();
	if (philo->last_meal_time > 0
		&& cur_time - philo->last_meal_time > philo->data->time_to_die)
	{
		philo->data->is_simulation_end = 1;
		pthread_mutex_unlock(&philo->data->death_mutex);
		print_status(philo, "died");
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

static int	check_all_ate_enough(t_data *data)
{
	int	i;
	int	all_ate_enough;

	if (data->required_meals <= 0)
		return (0);
	pthread_mutex_lock(&data->death_mutex);
	all_ate_enough = 1;
	i = 0;
	while (i < data->philo_count)
	{
		if (data->philos[i].meals_eaten < data->required_meals)
		{
			all_ate_enough = 0;
			break ;
		}
		i++;
	}
	if (all_ate_enough)
		data->is_simulation_end = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return (all_ate_enough);
}

static void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!is_simulation_ended(data))
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (check_if_died(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_ate_enough(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_timestamp();
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philosopher_routine, &data->philos[i]) != 0)
		{
			data->is_simulation_end = 1;
			while (--i >= 0)
				pthread_join(data->philos[i].thread, NULL);
			return (1);
		}
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
	{
		data->is_simulation_end = 1;
		return (1);
	}
	return (0);
}
