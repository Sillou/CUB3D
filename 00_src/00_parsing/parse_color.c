/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:52:55 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 22:53:36 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_f(char *line, int i, t_game *game);
static void	add_c(char *line, int i, t_game *game);

void	add_color(char *line, char str, t_game *game, int i)
{
	i++;
	while (ft_is_space(line[i]))
		i++;
	if (str == 'F')
	{
		add_f(line, i, game);
		game->config.floor_set = 1;
	}
	else if (str == 'C')
	{
		add_c(line, i, game);
		game->config.ceiling_set = 1;
	}
}

static void	add_f(char *line, int i, t_game *game)
{
	game->config.floor.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	game->config.floor.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	game->config.floor.b = ft_atoi(&line[i]);
}

static void	add_c(char *line, int i, t_game *game)
{
	game->config.ceiling.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	game->config.ceiling.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ',')
		i++;
	game->config.ceiling.b = ft_atoi(&line[i]);
}
