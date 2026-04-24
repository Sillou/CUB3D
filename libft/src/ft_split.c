/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:37:42 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 13:05:12 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_save_malloc(char **words_value, int i, size_t len)
{
	int	x;

	x = 0;
	words_value[i] = malloc(sizeof(char) * len);
	if (!words_value[i])
	{
		while (x < i)
			free(words_value[x++]);
		free(words_value);
		return (1);
	}
	return (0);
}

static int	ft_fill(char **words_value, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (ft_save_malloc(words_value, i, len + 1))
				return (1);
			ft_strlcpy(words_value[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

static size_t	ft_words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**words_value;

	if (!s)
		return (NULL);
	words = 0;
	words = ft_words_count(s, c);
	words_value = malloc(sizeof(char *) * (words + 1));
	if (words_value == NULL)
		return (NULL);
	words_value[words] = NULL;
	if (ft_fill(words_value, s, c))
		return (NULL);
	return (words_value);
}
