/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:51:52 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:41:38 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_print_int(int num, int *n)
{
	char	*dex_base;
	char	*str;

	dex_base = "0123456789";
	if (num < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) == -1)
			return (-1);
		if (num == INT_MIN)
		{
			if (write(STDOUT_FILENO, "2147483648", 10) == -1)
				return (-1);
			(*n) += 11;
			return (*n);
		}
		(*n)++;
		num *= -1;
	}
	if (num >= 10)
		if (ft_print_int(num / 10, n) == -1)
			return (-1);
	str = dex_base + (num % 10);
	if (ft_print_char(*str, *n) == -1)
		return (-1);
	return (++(*n));
}

int	ft_print_uint(unsigned int num, int *n)
{
	char	*dex_base;
	char	*str;

	dex_base = "0123456789";
	if (num >= 10)
		if (ft_print_int(num / 10, n) == -1)
			return (-1);
	str = dex_base + (num % 10);
	if (ft_print_char(*str, *n) == -1)
		return (-1);
	(*n)++;
	return (*n);
}
