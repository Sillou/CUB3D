/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_2D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:04:47 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/01 12:12:47 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_pixel(t_game *game, int x, int y, unsigned int color);
static void	ft_tile(t_game *game, int tx, int ty, unsigned int color);
static void	ft_draw_circle(t_game *game, int tx, int ty, unsigned int color);

static void	ft_put_pixel(t_game *game, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= game->map.width * game->tile
		|| y >= game->map.hight * game->tile)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_length) + (x
			* (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	ft_tile(t_game *game, int tx, int ty, unsigned int color)
{
	int	px;
	int	py;
	int	y;
	int	x;

	y = 0;
	px = tx * game->tile;
	py = ty * game->tile;
	while (y < game->tile)
	{
		x = 0;
		while (x < game->tile)
		{
			ft_put_pixel(game, px + x, py + y, color);
			x++;
		}
		y++;
	}
}

static void	ft_draw_circle(t_game *game, int tx, int ty, unsigned int color)
{
	int	y;
	int	r;
	int	x;

	game->player.cx = tx * game->tile + game->tile / 2;
	game->player.cy = ty * game->tile + game->tile / 2;
	r = game->tile / 2 - 2;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			game->player.dx = x;
			game->player.dy = y;
			if (game->player.dx * game->player.dx + game->player.dy
				* game->player.dy <= r * r)
				ft_put_pixel(game, game->player.cx + x,
					game->player.cy + y, color);
			x++;
		}
		y++;
	}
}

void	ft_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.hight)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.full[y][x] == '1')
				ft_tile(game, x, y, game->colors.wall);
			else if (game->map.full[y][x] == '0')
				ft_tile(game, x, y, game->colors.floor);
			else if (is_player(game->map.full[y][x]))
			{
				ft_tile(game, x, y, game->colors.floor);
				ft_draw_circle(game, x, y, game->colors.player);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
