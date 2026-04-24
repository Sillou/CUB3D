/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:18:45 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:05:38 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	ic;

	ic = (unsigned char)c;
	len = ft_strlen(s);
	if (ic == '\0')
		return ((char *)(s + len));
	while (len-- > 0)
	{
		if ((unsigned char)s[len] == ic)
			return ((char *)(s + len));
	}
	return (NULL);
}
