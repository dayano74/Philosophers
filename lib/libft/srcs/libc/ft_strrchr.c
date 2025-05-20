/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:09:21 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:52:18 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_ptr;
	int		s_length;

	s_length = ft_strlen(s);
	s_ptr = (char *)s + s_length - 1;
	if (c == '\0')
		return ((char *)s + s_length);
	while (s_length--)
	{
		if (*s_ptr == (char)c)
			return (s_ptr);
		s_ptr--;
	}
	return (NULL);
}
