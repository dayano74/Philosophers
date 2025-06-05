/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:15:16 by dayano            #+#    #+#             */
/*   Updated: 2025/06/05 20:25:52 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_usage(char *program_name)
{
	write(2, "Usage: ", 7);
	write(2, program_name, ft_strlen(program_name));
	write(2, " <number_of_philosophers> <time_to_die> ", 40);
	write(2, "<time_to_eat> <time_to_sleep> ", 30);
	write(2, "[optional: number_of_times_each_philosopher_must_eat]\n", 55);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(argc, argv, &data))
		return (_usage(argv[0]), 1);
	if (init_mutex_and_philo(&data) != 0)
		return (1);
	if (create_threads(&data) != 0)
		return (cleanup_resources(&data), 1);
	wait_for_threads(&data);
	cleanup_resources(&data);
	return (0);
}
