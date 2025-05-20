/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:19 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:32 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
