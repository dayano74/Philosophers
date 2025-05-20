/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:23:04 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:48 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;

	if (!dst)
		dst_length = 0;
	else
		dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= size)
		return (size + src_length);
	i = 0;
	while (src[i] != '\0' && size - dst_length - 1 - i > 0)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	if (dst)
		dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}
