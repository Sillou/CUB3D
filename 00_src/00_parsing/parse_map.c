/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:16:16 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 18:56:51 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_color(char *line, t_game *game);
static int	is_texture(char *line, t_game *game);
static int	is_empty_line(char *line);
static int	is_map(char *line, t_game *game);

int	parse_befor_map(char *line, t_game *game)
{
	if (is_empty_line(line))
		return (0);
	if (is_texture(line, game))
		return (0);
	if (is_color(line, game))
		return (0);
	if (is_map(line, game))
		return (1);
	free(line);
	msg_error("Invalid line in file", NULL, game, 1);
	return (0);
}

static int	is_color(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "F", 1))
	{
		add_color(line, 'F', game, i);
		return (1);
	}
	if (!ft_strncmp(&line[i], "C", 1))
	{
		add_color(line, 'C', game, i);
		return (1);
	}
	return (0);
}

static int	is_texture(char *line, t_game *game)
{
	int	i;

	i = skip_spaces(line, 0);
	if (!ft_strncmp(&line[i], "NO", 2) || !ft_strncmp(&line[i], "SO", 2)
		|| !ft_strncmp(&line[i], "WE", 2) || !ft_strncmp(&line[i], "EA", 2))
	{
		ft_texture(line, game);
		return (1);
	}
	return (0);
}

static int	is_map(char *line, t_game *game)
{
	int	i;

	(void)game;
	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
		if (!ft_is_space(line[i]))
			return (0);
		i++;
	}
	return (0);
}

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

