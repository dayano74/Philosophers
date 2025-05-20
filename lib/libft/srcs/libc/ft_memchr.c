/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:22:09 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:00 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;

	s_ptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*s_ptr == (unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
