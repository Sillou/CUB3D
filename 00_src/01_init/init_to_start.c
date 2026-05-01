/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:56:12 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/01 12:19:24 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	game->config.floor_set = 0;
	game->config.floor.r = 0;
	game->config.floor.g = 0;
	game->config.floor.b = 0;
	game->config.ceiling_set = 0;
	game->config.ceiling.r = 0;
	game->config.ceiling.g = 0;
	game->config.ceiling.b = 0;
	game->tile = 128;
	game->map.full = NULL;
	game->colors.wall = 0x888888;
	game->colors.floor = 0x444444;
	game->colors.player = 0xFF0000;
}
