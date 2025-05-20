/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:16:43 by dayano            #+#    #+#             */
/*   Updated: 2025/02/22 14:51:11 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (src_ptr < dest_ptr && src_ptr + n > dest_ptr)
	{
		src_ptr += n;
		dest_ptr += n;
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	else
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}
