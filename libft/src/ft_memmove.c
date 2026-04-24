/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:36:07 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:14:55 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (n == 0)
		return (dest);
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n -1;
		s += n -1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
