/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:01 by dayano            #+#    #+#             */
/*   Updated: 2025/02/25 14:14:07 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putlong_fd(long long int n, int fd)
{
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
			return ;
		n = -n;
	}
	if (n >= 10)
		ft_putlong_fd(n / 10, fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putlong_fd((long long int)n, fd);
}
