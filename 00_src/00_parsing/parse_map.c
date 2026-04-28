/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:16:16 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 19:31:19 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_texture(char *line, t_game *game);
static	int	is_empty_line(char *line);
static int	ft_is_space(char line);


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
	msg_error("Invalid line in file", NULL, game, 1);
	return (0);
}

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

static int	is_color(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(line, "F", 2))
		{
			add_color(line, "F");
			return (1);
		}
		if (ft_strncmp(line, "C", 2))
		{
			add_color(line, "C");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO", 3))
	{
		ft_texture(line, "NO", game);
		return (1);
	}
	if (ft_strncmp(line, "SO", 3))
	{
		ft_texture(line, "SO", game);
		return (1);
	}
	if (ft_strncmp(line, "WE", 3))
	{
		ft_texture(line, "WE", game);
		return (1);
	}
	if (ft_strncmp(line, "EA", 3))
	{
		ft_texture(line, "EA", game);
		return (1);
	}
	return (0);
}

static	int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]))
			i++;
		else
			return (1);
	}
	return (0);
}


