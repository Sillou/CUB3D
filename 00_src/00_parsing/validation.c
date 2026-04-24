/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:49:41 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/24 15:29:29 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(int argc, char **argv, t_game *game)
{
	int	i;

	if (argc > 2)
		ft_error(WG_INPUT1, game);
	if (argc < 2)
		ft_error(WG_INPUT2, game);
	i = ft_strlen(argv[1]);
	if (!ft_strncmp(&argv[1][i - 4], ".cub", 5))
		ft_error(WG_INPUT3, game);
}