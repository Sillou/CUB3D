/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:38 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 13:11:02 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		msg_error("MLX", "init error", game, 1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIN_W, WIN_H, "CUB3D");
	if (!game->mlx.win)
		msg_error("MLX", "windows open error", game, 1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIN_W, WIN_H);
	if (!game->mlx.img)
		msg_error("MLX", "image creation error", game, 1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_length, &game->mlx.endian);
	ft_init_player_dir(game);
	mlx_key_hook(game->mlx.win, ft_keycode_input, game);
	mlx_hook(game->mlx.win, 17, 0, ft_close_window, game);
	ft_raycast(game);
	mlx_loop(game->mlx.mlx);
}
