/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:43:11 by dayano            #+#    #+#             */
/*   Updated: 2025/03/10 15:53:30 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	return ((long)ft_strtoll(nptr, endptr, base));
}
