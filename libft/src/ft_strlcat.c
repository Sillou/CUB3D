/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:46:20 by alubrano          #+#    #+#             */
/*   Updated: 2025/10/09 11:10:04 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
	{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;
	size_t	k;

	lendest = 0;
	while (lendest < size && dest[lendest])
		lendest++;
	lensrc = ft_strlen(src);
	if (size == lendest)
		return (size + lensrc);
	i = 0;
	k = lendest;
	while (src[i] && i < (size - lendest -1))
		dest[k++] = src[i++];
	dest[k] = '\0';
	return (lendest + lensrc);
}
