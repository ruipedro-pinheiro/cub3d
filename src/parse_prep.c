/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:21:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/05 18:02:58 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

/* I've decided to return specific errors specifying why the map is not valid.
 There's still not real map validation from the rules but only basic checks
 0 = good/no errors
-1 = doesn't exist or fd error
 1 = not valid (any rules that are invalid following subject) TODO:
*/

static void	output_validation(int error, char *path_to_map)
{
	if (error == 1)
		(ft_putstr(path_to_map), ft_putendl_fd(" is not valid", 2));
	if (error == -1)
		(ft_putstr(path_to_map), ft_putendl_fd(" does not exist", 2));
}

static bool	check_extension(char *str, int len)
{
	if (len < 4)
		return (false);
	if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
		&& str[len - 4] == '.')
		return (true);
	return (false);
}

static char	**expand_map(char **map, int count_len, int i, char *line)
{
	char	**new;

	new = malloc(sizeof(char *) * (count_len + 2));
	if (!new)
		return (ft_putendl_fd("Error: couldn't malloc new map", 2), NULL);
	while (++i < count_len)
		new[i] = map[i];
	free(map);
	new[count_len] = line;
	new[count_len + 1] = NULL;
	return (new);
}

int	dup_map(t_game *game, int fd)
{
	char	*line;
	char	**map;
	char	**tmp;
	int		count_len;
	int		i;

	map = NULL;
	count_len = -1;
	while (++count_len >= 0)
	{
		i = -1;
		line = get_next_line(fd);
		if (!line || !line[0])
			break ;
		tmp = expand_map(map, count_len, i, line);
		if (!tmp)
			return (ft_strfree(map), free(line), close(fd), 1);
		map = tmp;
	}
	close(fd);
	if (!map)
		return (1);
	return (game->map = map, 0);
}

int	file_check(t_game *game)
{
	int	map_fd;
	int	error;

	error = 0;
	map_fd = open(game->path_to_map, O_RDONLY);
	if (map_fd == -1)
		return (output_validation(error = -1, game->path_to_map), error);
	if (!check_extension(game->path_to_map, ft_strlen(game->path_to_map)))
		error = 1;
	if (dup_map(game, map_fd))
		return (-1);
	if (validate(game))
		error = 1;
	output_validation(error, game->path_to_map);
	return (error);
}
