/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:21:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/14 15:56:41 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static bool	check_extension(char *str, int len)
{
	if (len < 4)
		return (false);
	if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
		&& str[len - 4] == '.')
		return (true);
	return (false);
}

char	**expand_map(char **map, int count_len, int i, char *line)
{
	char	**new;

	new = malloc(sizeof(char *) * (count_len + 2));
	if (!new)
		return (ft_putendl_fd("Error: couldn't malloc new map", 2), NULL);
	while (++i < count_len)
		new[i] = map[i];
	free(map);
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
	new[count_len] = line;
	new[count_len + 1] = NULL;
	return (new);
}

int	file_check(t_game *game)
{
	int	map_fd;
	int	error;

	error = 0;
	map_fd = open(game->path_to_map, O_RDONLY);
	if (map_fd == -1)
		return (ft_putendl_fd("Error\ncannot open map: ", 2), 1);
	if (!check_extension(game->path_to_map, ft_strlen(game->path_to_map)))
	{
		close(map_fd);
		return (ft_putendl_fd("Error\ninvalid .cub extension", 2), 1);
	}
	error = dup_buffer(game, map_fd);
	close(map_fd);
	if (error)
		return (error);
	if (validate(game))
		return (1);
	return (0);
}
