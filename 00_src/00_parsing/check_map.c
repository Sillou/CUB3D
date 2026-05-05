/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:15:42 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/05 21:26:21 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Lit le fichier de la carte et construit la structure de la map
void	check_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;
	int		map_start;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (msg_error(argv, "can not open file", game, errno));
	map_start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!map_start)
		{
			map_start = parse_befor_map(line, game);
			if (map_start)
				add_map_line(line, game);
		}
		else
			add_map_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	check_valid_map(game);
	return ;
}

// Ajoute une ligne à la map en l'allouant dynamiquement
void	add_map_line(char *line, t_game *game)
{
	char	**new_map;
	int		i;
	int		l;

	i = game->map.hight;
	new_map = ft_calloc(i + 2, sizeof(char *));
	if (!new_map)
		msg_error("malloc failed", NULL, game, 1);
	while (i-- > 0)
		new_map[i] = game->map.full[i];
	free(game->map.full);
	game->map.full = new_map;
	game->map.full[game->map.hight] = ft_strdup(line);
	game->map.full[game->map.hight + 1] = NULL;
	game->map.hight += 1;
	l = ft_strlen(line);
	if (l > game->map.width)
		game->map.width = l - 1;
}
