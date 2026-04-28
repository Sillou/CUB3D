/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:09:16 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 16:35:18 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error(char *str, char *error_msg)
{
	char	*msg;
	char	*tmp;

	if (str != NULL)
	{
		msg = ft_strjoin(str, ": ");
		if (!msg)
			return ;
		tmp = ft_strjoin(msg, error_msg);
		free(msg);
		if (!tmp)
			return ;
		msg = tmp;
	}
	else
		msg = ft_strdup(error_msg);
	if (msg)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(msg, 2);
		free(msg);
	}
}

void	msg_error(char *str, char *error_msg, t_game *game)
{
	print_error(str, error_msg);
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
