/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:16:29 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 13:37:24 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;

	game = ft_calloc(1, sizeof(t_game));
	game->config.no = NULL;
	check_args(argc, argv, game);
	printf("NO : %s \n", game->config.no);
	printf("SO : %s\n", game->config.so);
	printf("WE : %s\n", game->config.we);
	printf("EA : %s\n", game->config.ea);
	ft_clean(game);
	return (0);
}
