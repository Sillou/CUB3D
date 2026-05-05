/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 00:51:54 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/06 01:10:03 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	expect_number(char *line, int *i, t_game *game, int l);
static void	expect_comma(char *line, int *i, t_game *game, int l);
static void	moves_spaces(char *line, int *i);

//Verifie la bonne logique d'entree pour le couleurs
void	color_input(char *line, int i, t_game *game, int l)
{
	expect_number(line, &i, game, l);
	expect_comma(line, &i, game, l);
	expect_number(line, &i, game, l);
	expect_comma(line, &i, game, l);
	expect_number(line, &i, game, l);
	moves_spaces(line, &i);
	if (line[i] != '\0')
		msg_error("Wrong line F/C", CORT, game, 1);
}

// Saute tous les espaces et verifie que c'est bies un numbre
static void	expect_number(char *line, int *i, t_game *game, int l)
{
	moves_spaces(line, i);
	if (!ft_isdigit(line[*i]))
	{
		if (l == 1)
			msg_error("Wrong line F", CORT, game, 1);
		else
			msg_error("Wrong line C", CORT, game, 1);
	}
	while (ft_isdigit(line[*i]))
		(*i)++;
}

// Saute tous les espaces et verifie que c'est bies une virgule
static void	expect_comma(char *line, int *i, t_game *game, int l)
{
	moves_spaces(line, i);
	if (line[*i] != ',')
	{
		if (l == 1)
			msg_error("Wrong line F", CORT, game, 1);
		else
			msg_error("Wrong line C", CORT, game, 1);
	}
	(*i)++;
}

//Skipe les espaces en avance l'adresse directement
static void	moves_spaces(char *line, int *i)
{
	while (ft_is_space(line[*i]))
		(*i)++;
}
