/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:15:21 by dayano            #+#    #+#             */
/*   Updated: 2025/05/26 03:34:55 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	_get_sign(const char *nptr, int *i)
{
	if (nptr[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (nptr[*i] == '+')
		(*i)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (!((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '-'
			|| nptr[i] == '+'))
		return (0);
	sign = _get_sign(nptr, &i);
	result = 0;
	while (_is_digit(nptr[i]))
	{
		if (result > (LONG_MAX - (nptr[i] - '0')) / 10 && sign == -1)
			return ((int)LONG_MIN);
		else if (result > (LONG_MAX - (nptr[i] - '0')) / 10 && sign == 1)
			return ((int)LONG_MAX);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(sign * result));
}
