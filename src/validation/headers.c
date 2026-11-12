/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:46:48 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/11 11:09:27 by rpinheir         ###   ########.ch       */
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

static int	register_header(char *line, bool seen[6], t_game *game)
{
	int	id;

	id = is_identifier(line);
	if (id == HEADER_INVALID || seen[id])
		return (ft_putendl_fd("Error\ninvalid or duplicate header", 2), 1);
	if (id <= HEADER_EA)
	{
		if (validate_texture_path(game, line, id))
			return (1);
	}
	else if (validate_rgb(game, line, id))
		return (1);
	seen[id] = true;
	return (0);
}

static char	*get_header_name(int i)
{
	if (i == HEADER_NO)
		return ("NO");
	else if (i == HEADER_SO)
		return ("SO");
	else if (i == HEADER_WE)
		return ("WE");
	else if (i == HEADER_EA)
		return ("EA");
	else if (i == HEADER_F)
		return ("F");
	else if (i == HEADER_C)
		return ("C");
	else
		return (NULL);
}

static int	verify_registerd_headers(bool *seen)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!seen[i])
		{
			ft_putstr_fd(FG_BOLD_RED "Error\nmissing header ", 2);
			ft_putstr_fd(get_header_name(i), 2);
			ft_putendl_fd(FG_DEFAULT, 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	validate_headers(t_game *game)
{
	char	*line;
	int		j;
	bool	seen[6];

	game->cursor = 0;
	ft_bzero(seen, sizeof(seen));
	while (game->config[game->cursor])
	{
		line = game->config[game->cursor];
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		line += j;
		if (line[0] == '\n' || line[0] == '\0')
		{
			game->cursor++;
			continue ;
		}
		if (line[0] == '1')
			break ;
		if (register_header(line, seen, game))
			return (1);
		game->cursor++;
	}
	return (verify_registerd_headers(seen));
}
