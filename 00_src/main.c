/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:16:29 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/30 18:15:58 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;
	int	i = -1;

	game = ft_calloc(1, sizeof(t_game));
	init_start(game);
	check_args(argc, argv, game);
	init_mlx(game);
	printf("NO : %s \n", game->config.no);
	printf("SO : %s\n", game->config.so);
	printf("WE : %s\n", game->config.we);
	printf("EA : %s\n", game->config.ea);
	printf("HIGHT: %d\n", game->map.hight);
	printf("WIDTH: %d\n", game->map.width);
	printf("PLAYER : x = %d\t y = %d\n", game->player.x, game->player.y);
	while (++i < game->map.hight)
		printf("%s", game->map.full[i]);
	ft_clean(game);
	return (0);
}
