/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:04:30 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/30 18:11:33 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.full[i])
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
	game->map.full = NULL;
}

void	free_config(t_game *game)
{
	if (game->config.no)
	{
		free(game->config.no);
		game->config.no = NULL;
	}
	if (game->config.so)
	{
		free(game->config.so);
		game->config.so = NULL;
	}
	if (game->config.we)
	{
		free(game->config.we);
		game->config.we = NULL;
	}
	if (game->config.ea)
	{
		free(game->config.ea);
		game->config.ea = NULL;
	}
}

void	free_mlx(t_game *g)
{
	if (g->mlx.img)
		mlx_destroy_image(g->mlx.mlx, g->mlx.img);
	if (g->mlx.win)
		mlx_destroy_window(g->mlx.mlx, g->mlx.win);
	if (g->mlx.mlx)
		mlx_destroy_display(g->mlx.mlx);
	free(g->mlx.mlx);
}
