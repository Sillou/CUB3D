/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:57 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 15:33:38 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	ft_rotate(t_game *game, double rot);
static void	ft_move(t_game *game, double dx, double dy);

static void	ft_rotate(t_game *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot)
		- game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot)
		+ game->player.dir_y * cos(rot);
	game->player.plane_x = game->player.plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_y * cos(rot);
}

static void	ft_move(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (game->map.full[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
	if (game->map.full[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
}

int	ft_keycode_input(int key, t_game *game)
{
	if (key == 65363 || key == 100)
		ft_rotate(game, ROT_SPEED);
	else if (key == 65361 || key == 97)
		ft_rotate(game, -ROT_SPEED);
	else if (key == 65362 || key == 119)
		ft_move(game, game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	else if (key == 65364 || key == 115)
		ft_move(game, -game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	// else if (key == 100)
	// 	ft_move(game, game->player.plane_x * MOVE_SPEED,
			// game->player.plane_y * MOVE_SPEED);
	// else if (key == 97)
	// 	ft_move(game, -game->player.plane_x * MOVE_SPEED,
	// 		-game->player.plane_y * MOVE_SPEED);
	else if (key == 65307)
		msg_error("EXIT GAME", NULL, game, 0);
	ft_raycast(game);
	return (0);
}
