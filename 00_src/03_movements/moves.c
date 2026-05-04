/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:57 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 21:45:26 by alubrano         ###   ########.fr       */
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

int	ft_key_press(int key, t_game *game)
{
	if (key == 119)
		game->player.keys.key_w = 1;
	else if (key == 115)
		game->player.keys.key_s = 1;
	else if (key == 97)
		game->player.keys.key_a = 1;
	else if (key == 100)
		game->player.keys.key_d = 1;
	else if (key == 65361)
		game->player.keys.key_left = 1;
	else if (key == 65363)
		game->player.keys.key_right = 1;
	else if (key == 65307)
		msg_error("EXIT GAME", NULL, game, 0);
	return (0);
}

int	ft_key_release(int key, t_game *game)
{
	if (key == 119)
		game->player.keys.key_w = 0;
	else if (key == 115)
		game->player.keys.key_s = 0;
	else if (key == 97)
		game->player.keys.key_a = 0;
	else if (key == 100)
		game->player.keys.key_d = 0;
	else if (key == 65361)
		game->player.keys.key_left = 0;
	else if (key == 65363)
		game->player.keys.key_right = 0;
	return (0);
}

int	ft_game_loop(t_game *game)
{
	if (game->player.keys.key_right)
		ft_rotate(game, ROT_SPEED);
	if (game->player.keys.key_left)
		ft_rotate(game, -ROT_SPEED);
	if (game->player.keys.key_w)
		ft_move(game, game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	if (game->player.keys.key_s)
		ft_move(game, -game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	if (game->player.keys.key_d)
		ft_move(game, -game->player.dir_y * MOVE_SPEED,
			game->player.dir_x * MOVE_SPEED);
	if (game->player.keys.key_a)
		ft_move(game, game->player.dir_y * MOVE_SPEED,
			-game->player.dir_x * MOVE_SPEED);
	ft_raycast(game);
	return (0);
}
