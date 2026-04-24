/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:44:32 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 14:19:14 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strl1;
	size_t	strl2;
	char	*dest;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strl1 = ft_strlen(s1);
	strl2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (strl1 + strl2 + 1));
	if (!dest)
		return (NULL);
	start = dest;
	while (s1 != NULL && *s1)
		*dest++ = *s1++;
	while (s2 != NULL && *s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (start);
}
