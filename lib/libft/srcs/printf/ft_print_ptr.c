/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:03:21 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:41:43 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_print_ptr_hex(uintptr_t num, int *n)
{
	char	c;
	char	*low_hex_base;

	low_hex_base = "0123456789abcdef";
	if (num >= 16)
		if (ft_print_ptr_hex(num / 16, n) == -1)
			return (-1);
	c = low_hex_base[num % 16];
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (-1);
	(*n)++;
	return (*n);
}

int	ft_print_ptr(uintptr_t num, int *n)
{
	int	error;

	if (!num)
	{
		error = write(STDOUT_FILENO, "(nil)", 5);
		if (error == -1)
			return (-1);
		(*n) += 5;
		return (*n);
	}
	if (write(STDOUT_FILENO, "0x", 2) == -1)
		return (-1);
	(*n) += 2;
	return (ft_print_ptr_hex(num, n));
}
