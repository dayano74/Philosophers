/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:48:32 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:41:47 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_print_str(char *s, int n)
{
	if (!s)
	{
		if (write(STDOUT_FILENO, "(null)", 6) == -1)
			return (-1);
		n += 6;
		return (n);
	}
	while (*s)
	{
		n = ft_print_char(*s, n);
		s++;
	}
	return (n);
}
