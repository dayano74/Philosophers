/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:04:27 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:49:11 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	long long	n_cpy;

	len = get_num_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	n_cpy = n;
	if (n_cpy < 0)
	{
		result[0] = '-';
		n_cpy = -n_cpy;
	}
	if (n_cpy == 0)
		result[0] = '0';
	while (n_cpy > 0)
	{
		result[--len] = (n_cpy % 10) + '0';
		n_cpy /= 10;
	}
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(123);
// 	printf("result: %s\n", result);
// 	free(result);
// 	result = ft_itoa(-123);
// 	printf("result: %s\n", result);
// 	free(result);
// 	result = ft_itoa(0);
// 	printf("result: %s\n", result);
// 	free(result);
// 	result = ft_itoa(INT_MAX);
// 	printf("result: %s\n", result);
// 	free(result);
// 	result = ft_itoa(INT_MIN);
// 	printf("result: %s\n", result);
// 	free(result);
// 	return (0);
// }
