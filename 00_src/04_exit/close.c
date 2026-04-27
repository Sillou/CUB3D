/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:09:16 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/27 13:55:50 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *error, t_game *game)
{
	if (error)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(error, 2);
	}
	if (game)
		ft_clean(game);
	exit(1);
}

void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	// if (game)
	// {

	// }
	free (game);
	game = NULL;
}
