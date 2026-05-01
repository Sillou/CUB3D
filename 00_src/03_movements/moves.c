/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:57 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/01 12:35:55 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_it(t_game *game, int w, int z)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	game->map.full[y][x] = '0';
	game->player.x += z;
	game->player.y += w;
	game->map.full[game->player.y][game->player.x] = 'N';
	ft_map(game);
}

int	ft_keycode_input(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	// if ((key == 65363 || key == 100) && game->map.full[y][x + 1] != '1')
	// 	ft_move_it(game, 0, +1);
	// if ((key == 65361 || key == 97) && game->map.full[y][x - 1] != '1')
	// 	ft_move_it(game, 0, -1);
	if ((key == 65362 || key == 119) && game->map.full[y - 1][x] != '1')
		ft_move_it(game, -1, 0);
	if ((key == 65364 || key == 115) && game->map.full[y + 1][x] != '1')
		ft_move_it(game, +1, 0);
	if (key == 65307)
		msg_error("EXIT GAME", NULL, game, 0);
	return (0);
}
