/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:00:18 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:41:35 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_print_hex(unsigned int num, int *n)
{
	char	*low_hex_base;
	char	*str;

	low_hex_base = "0123456789abcdef";
	if (num >= 16)
	{
		if (ft_print_hex(num / 16, n) == -1)
			return (-1);
	}
	str = low_hex_base + (num % 16);
	if (ft_print_char(*str, *n) == -1)
		return (-1);
	(*n)++;
	return (*n);
}

int	ft_print_upperx(unsigned int num, int *n)
{
	char	*low_hex_base;
	char	*str;

	low_hex_base = "0123456789ABCDEF";
	if (num >= 16)
	{
		if (ft_print_upperx(num / 16, n) == -1)
			return (-1);
	}
	str = low_hex_base + (num % 16);
	if (ft_print_char(*str, *n) == -1)
		return (-1);
	(*n)++;
	return (*n);
}
