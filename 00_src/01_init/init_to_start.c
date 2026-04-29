/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:56:12 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 15:00:36 by alubrano         ###   ########.fr       */
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
}
