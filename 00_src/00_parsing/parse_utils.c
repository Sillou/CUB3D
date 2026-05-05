/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 22:36:48 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 20:51:11 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Retourne 1 si le caractère est un espace, une tabulation ou un saut de ligne
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

// Ignore les espaces au début d'une ligne et retourne l'indice du premier caractère non-espace
int	skip_spaces(char *line, int i)
{
	while (ft_is_space(line[i]))
		i++;
	return (i);
}
