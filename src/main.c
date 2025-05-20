/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:15:16 by dayano            #+#    #+#             */
/*   Updated: 2025/05/19 22:27:30 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	usage(char *program_name)
{
	printf("Usage: %s ", program_name);
	printf("<number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> ");
	printf("[optional: number_of_times_each_philosopher_must_eat]\n");
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (usage(argv[0]), 1);
	return (0);
}
