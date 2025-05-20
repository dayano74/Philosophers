/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:01:19 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:13:40 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char *fmt, int n)
{
	fmt++;
	if (*fmt == 'c')
		n = ft_print_char(va_arg(ap, int), n);
	else if (*fmt == 's')
		n = ft_print_str(va_arg(ap, char *), n);
	else if (*fmt == 'd' || *fmt == 'i')
		n = ft_print_int(va_arg(ap, int), &n);
	else if (*fmt == 'u')
		n = ft_print_uint(va_arg(ap, unsigned int), &n);
	else if (*fmt == 'x')
		n = ft_print_hex(va_arg(ap, unsigned int), &n);
	else if (*fmt == 'X')
		n = ft_print_upperx(va_arg(ap, unsigned int), &n);
	else if (*fmt == 'p')
		n = ft_print_ptr(va_arg(ap, uintptr_t), &n);
	else if (*fmt == '%')
	{
		if (write(STDOUT_FILENO, "%", 1) == -1)
			return (-1);
		n++;
	}
	return (n);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		if (*fmt == '%')
		{
			n = ft_format(ap, (char *)fmt, n);
			fmt++;
		}
		else
			n = ft_print_char(*(char *)fmt, n);
		fmt++;
	}
	va_end(ap);
	return (n);
}
