/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:15:42 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 18:23:01 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
			map_start = parse_befor_map(line, game); //TODO
		else
			add_map_line(line, game);//TODO
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	check_config(game); // TODO
	return ;
}

