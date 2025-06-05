/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:15:21 by dayano            #+#    #+#             */
/*   Updated: 2025/06/05 18:33:21 by dayano           ###   ########.fr       */
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

long	ft_atoi(const char *nptr)
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
			return (LONG_MIN);
		else if (result > (LONG_MAX - (nptr[i] - '0')) / 10 && sign == 1)
			return (LONG_MAX);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		return (-1);
	return ((long)(sign * result));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
