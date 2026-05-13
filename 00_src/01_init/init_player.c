/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:04:47 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/13 15:18:45 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	is_n(t_game *game);
static void	is_s(t_game *game);
static void	is_e(t_game *game);
static void	is_w(t_game *game);

/* Initializes the player direction and position
	based on the character found on the map */
void	ft_init_player_dir(t_game *game)
{
	char	c;

	c = game->map.full[game->player.y][game->player.x];
	game->player.pos_x = game->player.x + 0.5;
	game->player.pos_y = game->player.y + 0.5;
	if (c == 'N')
		is_n(game);
	else if (c == 'S')
		is_s(game);
	else if (c == 'E')
		is_e(game);
	else if (c == 'W')
		is_w(game);
	game->map.full[game->player.y][game->player.x] = '0';
}

/* Orients the player facing north */
static void	is_n(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0.0;
}

/* Orients the player facing south */
static void	is_s(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = 1.0;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0.0;
}

/* Orients the player facing east */
static void	is_e(t_game *game)
{
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
}

/* Orients the player facing west */
static void	is_w(t_game *game)
{
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = -0.66;
}
