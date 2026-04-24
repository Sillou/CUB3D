/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:35:38 by alubrano          #+#    #+#             */
/*   Updated: 2025/10/09 13:12:43 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = ft_strlen(src);
	if (!size)
		return (len);
	if (size > 0)
	{
		if (len >= size)
			n = size - 1;
		else
			n = len;
		ft_memcpy(dest, src, n);
		dest[n] = '\0';
	}
	return (len);
}
