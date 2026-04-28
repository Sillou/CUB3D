/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:24:09 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 20:16:16 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_config(char *line, t_game *game, int i, int j);
static void	ft_is_xpm(char *line, int i, t_game *game);
static char	*extract_texture_path(char *line, int i);


void	ft_texture(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO", 2))
		game->config.no = extract_texture_path(line, i + 1);
	else if (!ft_strncmp(&line[i], "SO", 2))
		game->config.so = extract_texture_path(line, i + 2);
	else if (!ft_strncmp(&line[i], "EA", 2))
		game->config.ea = extract_texture_path(line, i + 2);
	else if (!ft_strncmp(&line[i], "WE", 2))
		game->config.we = extract_texture_path(line, i + 2);
	else
		msg_error("Invalid texture identifier", NULL, game, 1);
}

static void	check_config(char *line, t_game *game, int i, int j)
{
	while (ft_is_space(line[i]))
		i++;
	ft_is_xpm(line, i, game);
	if (j == 1)
	{
		if (game->config.no == NULL)
			game->config.no = extract_texture_path(line, i);
	}
	if (j == 2)
	{
		if (game->config.so == NULL)
			game->config.so = extract_texture_path(line, i);
	}
	if (j == 3)
	{
		if (game->config.we == NULL)
			game->config.we = extract_texture_path(line, i);
	}
	if (j == 4)
	{
		if (game->config.ea == NULL)
			game->config.ea = extract_texture_path(line, i);
	}
}

static void	ft_is_xpm(char *line, int i, t_game *game)
{
	int fd;

	while (ft_is_space(line[i]))
		i++;
	fd = open(&line[i], O_RDONLY);
	if (fd == -1)
	{
		msg_error("Invalid XPM path", NULL, game, 1);
	}
	close(fd);
}

static char	*extract_texture_path(char *line, int i)
{
	while (ft_is_space(line[i]))
		i++;
	return ft_strdup(&line[i]);
}
