/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:56:12 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 22:55:54 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_second(t_game *game);

// Initialise toutes les valeurs de la structure t_game à leur valeur de départ
void	init_start(t_game *game)
{
	game->config.no = NULL;
	game->config.so = NULL;
	game->config.ea = NULL;
	game->config.we = NULL;
	game->map.hight = 0;
	game->map.width = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.pos_x = 0.0;
	game->player.pos_y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	init_second(game);
}

// Initialise les valeurs secondaires de la structure t_game
static void	init_second(t_game *game)
{
	game->config.floor_set = 0;
	game->config.floor.r = 0;
	game->config.floor.g = 0;
	game->config.floor.b = 0;
	game->config.ceiling_set = 0;
	game->config.ceiling.r = 0;
	game->config.ceiling.g = 0;
	game->config.ceiling.b = 0;
	game->map.full = NULL;
	game->colors.wall = 0x888888;
	game->player.keys.key_w = 0;
	game->player.keys.key_s = 0;
	game->player.keys.key_d = 0;
	game->player.keys.key_a = 0;
	game->player.keys.key_left = 0;
	game->player.keys.key_right = 0;
}
