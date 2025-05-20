/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:50:33 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:52 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (src_length);
}
