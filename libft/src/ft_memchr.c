/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:54:59 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:14:46 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		testc;

	str = (const unsigned char *)s;
	testc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == testc)
			return ((void *)((const unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
