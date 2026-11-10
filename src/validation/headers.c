/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:46:48 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/10 17:57:12 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

static int	is_identifier(char *line)
{
	if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		return (HEADER_C);
	else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
		return (HEADER_F);
	else if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (HEADER_NO);
	else if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (HEADER_SO);
	else if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (HEADER_WE);
	else if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
		return (HEADER_EA);
	return (HEADER_INVALID);
}

int	validate_headers(t_game *game)
{
	char	*line;
	int		i;
	int		j;
	int		id;
	bool	seen[6];

	ft_bzero(seen, sizeof(seen));
	i = 0;
	while (game->map[i])
	{
		line = game->map[i];
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		line += j;
		if (line[0] == '\n')
			i++;
		id = is_identifier(line);
		if (id == HEADER_INVALID)
			return (1);
		if (seen[id])
			return (1);
		seen[id] = true;
		i++;
	}
	return (0);
}
