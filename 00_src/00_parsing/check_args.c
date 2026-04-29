/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:49:41 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 20:50:55 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char *argv);
static void	check_file(char *argv, t_game *game);

void	check_args(int argc, char **argv, t_game *game)
{
	int	i;

	if (argc > 2)
		msg_error(WG_INPUT1, NULL, game, 1);
	if (argc < 2)
		msg_error(WG_INPUT2, NULL, game, 1);
	i = ft_strlen(argv[1]);
	if (i < 5)
		msg_error(WG_INPUT2, NULL, game, 1);
	if (ft_strncmp(&argv[1][i - 4], ".cub", 5))
		msg_error(WG_INPUT3, NULL, game, 1);
	check_file(argv[1], game);
	check_map(argv[1], game);
}

static bool	is_dir(char *argv)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(argv, __O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

static void	check_file(char *argv, t_game *game)
{
	int	fd;

	if (is_dir(argv))
		return (msg_error(NULL, WG_FILE, game, errno));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (msg_error(argv, "ERROR open file", game, errno));
}
