/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:24:09 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 20:49:12 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_texture_path(char *line, int i, t_game *game);

void	ft_texture(char *line, t_game *game)
{
	int	i;

	i = 0;
	i = skip_spaces(line, 0);
	if (!ft_strncmp(&line[i], "NO", 2) && game->config.no == NULL)
		game->config.no = extract_texture_path(line, i + 2, game);
	else if (!ft_strncmp(&line[i], "SO", 2) && game->config.so == NULL)
		game->config.so = extract_texture_path(line, i + 2, game);
	else if (!ft_strncmp(&line[i], "WE", 2) && game->config.we == NULL)
		game->config.we = extract_texture_path(line, i + 2, game);
	else if (!ft_strncmp(&line[i], "EA", 2) && game->config.ea == NULL)
		game->config.ea = extract_texture_path(line, i + 2, game);
	else
	{
		free (line);
		line = NULL;
		msg_error("Invalid texture identifier", NULL, game, 1);
	}
}

static char	*extract_texture_path(char *line, int i, t_game *game)
{
	int		fd;
	char	*path;
	int		len;

	i = skip_spaces(line, i);
	path = ft_strdup(&line[i]);
	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == '\r'
			|| path[len - 1] == ' ' || path[len - 1] == '\t'))
		path[--len] = '\0';
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		path = NULL;
		free(line);
		msg_error("Invalid XPM path", NULL, game, 1);
	}
	close(fd);
	return (path);
}
