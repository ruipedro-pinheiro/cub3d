/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:53:07 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/14 15:57:02 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*skip_empty(char *line, int fd, char ***buffer, t_game *game)
{
	while (1)
	{
		line = get_next_line(fd);
		if (buffer == &game->map)
		{
			if (line[0] == '\n')
				return (ft_putendl_fd("Error\nFound newline on map", 2), NULL);
		}
		if (!line || line[0] != '\n')
			return (line);
		free(line);
	}
}

int	dup_buffer(t_game *game, int fd)
{
	char	*line;
	char	***buffer;
	int		count_len;

	buffer = &game->config;
	count_len = -1;
	while (++count_len >= 0)
	{
		line = skip_empty(line, fd, buffer, game);
		if (!line)
			break ;
		if (line[0] == '1' && buffer == &game->config)
		{
			buffer = &game->map;
			count_len = 0;
		}
		*buffer = expand_map(*buffer, count_len, -1, line);
		if (!*buffer)
			return (ft_strfree(*buffer), free(line), close(fd), -1);
	}
	if (!game->config || !game->map)
		return (ft_putendl_fd("Error\nempty map or header", 2), 1);
	return (0);
}
