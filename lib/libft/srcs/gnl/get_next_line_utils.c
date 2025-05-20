/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:07 by dayano            #+#    #+#             */
/*   Updated: 2025/03/29 20:54:31 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;
	char	*ptr_result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ptr_result = result;
	while (*s1)
		*ptr_result++ = *s1++;
	while (*s2)
		*ptr_result++ = *s2++;
	*ptr_result = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;
	int		s_length;

	s_length = ft_strlen((char *)s);
	s_ptr = (char *)s;
	while (*s_ptr)
	{
		if (*s_ptr == (char)c)
			return (s_ptr);
		s_ptr++;
	}
	if (c == '\0')
		return ((char *)s + s_length);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;

	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	ptr = dup;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
