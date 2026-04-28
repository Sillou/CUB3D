/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:49:41 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 16:49:55 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char *argv)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(argv,__O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

static void	check_file(char *argv, t_game * game)
{
	int	fd;

	if (is_dir(argv))
		return (msg_error(NULL, WG_FILE, game));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (msg_error(argv, "ERROR open file", game));
}

void	check_args(int argc, char **argv, t_game *game)
{
	int	i;

	if (argc > 2)
		msg_error(NULL, WG_INPUT1, game);
	if (argc < 2)
		msg_error(NULL, WG_INPUT2, game);
	i = ft_strlen(argv[1]);
	if (i < 5)
		msg_error(NULL, WG_INPUT2, game);
	if (ft_strncmp(&argv[1][i - 4], ".cub", 5))
		msg_error(NULL, WG_INPUT3, game);
	check_file(argv[1], game);
}
