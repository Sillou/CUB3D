/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 22:36:48 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/13 15:18:33 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Returns 1 if the character is a space, tab, or newline */
int	ft_is_space(char line)
{
	if (line == ' ')
		return (1);
	if (line == '\t')
		return (1);
	if (line == '\r')
		return (1);
	if (line == '\n')
		return (1);
	if (line == '\f')
		return (1);
	if (line == '\v')
		return (1);
	return (0);
}

/* Skips leading whitespace in a line
	and returns the index of the first non-space character */
int	skip_spaces(char *line, int i)
{
	while (ft_is_space(line[i]))
		i++;
	return (i);
}
