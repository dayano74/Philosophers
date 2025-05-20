/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:35:03 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:24 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **result, int j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
	return (NULL);
}

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	char	*start;

	i = 0;
	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !(result))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			result[i] = ft_strndup(start, s - start);
			if (!result[i++])
				return (ft_free_all(result, i));
		}
	}
	result[i] = NULL;
	return (result);
}
