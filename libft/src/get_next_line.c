/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:54:40 by alubrano          #+#    #+#             */
/*   Updated: 2025/12/19 14:24:46 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gnl_free(char **ptr)
{
	if (*ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

static int	ft_gnl_get_the_n(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

static char	*ft_gnl_clean_line(char *line_buffer, char **static_str)
{
	size_t	i;
	char	*tmp;
	size_t	len;

	i = 0;
	len = ft_strlen(line_buffer);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	tmp = line_buffer;
	if (line_buffer[i] == '\0')
		line_buffer = ft_substr(tmp, 0, len);
	if (line_buffer[i] == '\n')
		line_buffer = ft_substr(tmp, 0, i + 1);
	if (!line_buffer)
	{
		free(tmp);
		tmp = NULL;
		*static_str = NULL;
		return (NULL);
	}
	*static_str = NULL;
	if (line_buffer[i] == '\n' && len > i + 1)
		*static_str = ft_substr(tmp, i + 1, (len - (i + 1)));
	tmp = NULL;
	return (line_buffer);
}

static char	*ft_gnl_add_line(int fd, char *line_buffer, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (!ft_gnl_get_the_n(line_buffer) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_GNL_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			free(line_buffer);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		tmp = line_buffer;
		line_buffer = ft_strjoin(tmp, buffer);
		if (!line_buffer)
			return (ft_gnl_free(&buffer));
		free(tmp);
		tmp = NULL;
	}
	free(buffer);
	return (line_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_str[FD_GNL_MAX];
	char		*line_buffer;
	char		*tmp;
	char		*buffer;

	if (fd < 0 || fd > FD_GNL_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_GNL_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_GNL_SIZE + 1));
	if (!buffer)
		return (NULL);
	line_buffer = static_str[fd];
	static_str[fd] = NULL;
	tmp = ft_gnl_add_line(fd, line_buffer, buffer);
	if (!tmp)
		return (NULL);
	line_buffer = NULL;
	line_buffer = ft_gnl_clean_line(tmp, &static_str[fd]);
	free(tmp);
	return (line_buffer);
}
