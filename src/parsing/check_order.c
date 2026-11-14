/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:53:07 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/14 16:30:03 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	check_map_last(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n' || line[i] == ' ')
	{
		i++;
	}
	if ((is_identifier(line)) < 6)
	{
		ft_putendl_fd("Error\nFound map before header", 2);
		return (1);
	}
	return (0);
}

int	skip_empty(char **line, int fd, char ***buffer, t_game *game)
{
	while (1)
	{
		*line = get_next_line(fd);
		if (!*line)
			return (0);
		if (check_map_last(*line))
			return (-1);
		if ((*line)[0] != '\n')
			return (1);
		if (buffer == &game->map)
			return (free(*line), ft_putendl_fd("Error\nFound newline on map",
					2), -1);
		free(*line);
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
		if (skip_empty(&line, fd, buffer, game) == -1)
			return (1);
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
