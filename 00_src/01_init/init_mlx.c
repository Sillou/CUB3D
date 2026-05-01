/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:38 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/01 12:27:38 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	int	size_x;
	int	size_y;

	size_x = game->map.width * game->tile;
	size_y = game->map.hight * game->tile;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		msg_error("MLX", "init error", game, 1);
	game->mlx.win = mlx_new_window(game->mlx.mlx, size_x, size_y, "CUB3D");
	if (!game->mlx.win)
		msg_error("MLX", "windows open error", game, 1);
	game->mlx.img = mlx_new_image(game->mlx.mlx, size_x, size_y);
	if (!game->mlx.img)
		msg_error("MLX", "image creation error", game, 1);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_length, &game->mlx.endian);
	mlx_key_hook(game->mlx.win, ft_keycode_input, game);
	mlx_hook(game->mlx.win, 17, 0, ft_close_window, game);
	ft_map(game);
	mlx_loop(game->mlx.mlx);
}
