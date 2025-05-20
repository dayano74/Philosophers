/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:57:54 by dayano            #+#    #+#             */
/*   Updated: 2024/11/17 13:31:48 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_format(va_list ap, char *fmt, int n);
int	ft_print_str(char *s, int n);
int	ft_print_char(char c, int n);
int	ft_print_int(int num, int *n);
int	ft_print_uint(unsigned int num, int *n);
int	ft_print_hex(unsigned int num, int *n);
int	ft_print_upperx(unsigned int num, int *n);
int	ft_print_ptr(uintptr_t num, int *n);

#endif
