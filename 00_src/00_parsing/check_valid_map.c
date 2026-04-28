/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 22:50:41 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 22:53:25 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	check_config_complete(t_game *game)
{
	if (!game->config.no || !game->config.so
		|| !game->config.we || !game->config.ea)
		msg_error("Missing texture identifier", NULL, game, 1);
	if (!game->config.floor_set)
		msg_error("Missing floor color (F)", NULL, game, 1);
	if (!game->config.ceiling_set)
		msg_error("Missing ceiling color (C)", NULL, game, 1);
}

static void	check_color_range(t_color color, char *name, t_game *game)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
		msg_error("Color value out of range (0-255)", name, game, 1);
}

static void	check_map_chars(t_game *game)
{
	int	row;
	int	col;
	int	players;

	row = 0;
	players = 0;
	while (row < game->map.hight)
	{
		col = 0;
		while (game->map.map[row][col] && game->map.map[row][col] != '\n')
		{
			if (!ft_strchr("01 \t\rNSEW", game->map.map[row][col]))
				msg_error("Invalid character in map", NULL, game, 1);
			if (is_player(game->map.map[row][col]))
				players++;
			col++;
		}
		row++;
	}
	if (players != 1)
		msg_error("Map must have exactly one player (N/S/E/W)", NULL, game, 1);
}

static int	is_open(char **map, int row, int col, int height)
{
	int	len;

	if (row < 0 || row >= height)
		return (1);
	len = (int)ft_strlen(map[row]);
	if (col < 0 || col >= len)
		return (1);
	if (map[row][col] == ' ' || map[row][col] == '\t'
		|| map[row][col] == '\n')
		return (1);
	return (0);
}

static void	check_map_closed(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.hight)
	{
		col = 0;
		while (game->map.map[row][col] && game->map.map[row][col] != '\n')
		{
			if (game->map.map[row][col] == '0'
				|| is_player(game->map.map[row][col]))
				if (is_open(game->map.map, row - 1, col, game->map.hight)
					|| is_open(game->map.map, row + 1, col, game->map.hight)
					|| is_open(game->map.map, row, col - 1, game->map.hight)
					|| is_open(game->map.map, row, col + 1, game->map.hight))
					msg_error("Map is not closed by walls", NULL, game, 1);
			col++;
		}
		row++;
	}
}

void	check_valid_map(t_game *game)
{
	check_config_complete(game);
	check_color_range(game->config.floor, "F", game);
	check_color_range(game->config.ceiling, "C", game);
	check_map_chars(game);
	check_map_closed(game);
}

