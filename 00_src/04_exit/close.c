/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:09:16 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 23:10:59 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error(char *str, char *error_msg);

void	msg_error(char *str, char *error_msg, t_game *game, int code)
{
	print_error(str, error_msg);
	if (game)
		ft_clean(game);
	exit(code);
}

void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	if (game->map.map)
		free_map(game);
	if (game->config.no || game->config.so
		|| game->config.we || game->config.ea)
		free_config(game);
	free(game);
}

static void	print_error(char *str, char *error_msg)
{
	ft_putendl_fd("Error", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (error_msg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_msg, 2);
	}
	ft_putstr_fd("\n", 2);
}
