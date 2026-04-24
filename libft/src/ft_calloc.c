/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:42:37 by alubrano          #+#    #+#             */
/*   Updated: 2025/10/09 11:08:11 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*copy;
	size_t	total;

	total = nmemb * size;
	if (nmemb != 0 && (total / nmemb) != size)
		return (0);
	copy = malloc(total);
	if (!copy)
		return (NULL);
	ft_memset(copy, 0, total);
	return (copy);
}
