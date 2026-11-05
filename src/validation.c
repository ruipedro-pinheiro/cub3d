/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:21:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/04 19:34:20 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

/* I've decided to return specific errors specifying why the map is not valid.
 There's still not real map validation from the rules but only basic checks
 0 = good/no errors
-1 = doesn't exist
 1 = not valid (any rules that are invalid following subject) TODO:
*/

static void	output_validation(int error, char *pathToMap)
{
	if (error == 1)
		(ft_putstr(pathToMap), ft_putendl_fd(" is not valid", 2));
	if (error == -1)
		(ft_putstr(pathToMap), ft_putendl_fd(" does not exist", 2));
}

static bool	check_extension(char *str, int len)
{
	if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
		&& str[len - 4] == '.')
		return (true);
	return (false);
}

int	dup_map(int fd)
{
	char	*line;
	char	**map;
	char	**new;
	int		count_len;

	map = NULL;
	new = NULL;
	count_len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !line[0])
			break ;
		new = malloc(sizeof(char *) * (count_len + 2));
		new[count_len] = line;
		free(map);
		map = new;
		count_len++;
	}
	return (0);
}
//TODO: set count_len and char **map to t_game struct

int	validate_map(char *pathToMap)
{
	int		len;
	int		map_fd;
	int		error;

	error = 0;
	map_fd = open(pathToMap, O_RDONLY);
	if (map_fd == -1)
		return (output_validation(error = -1, pathToMap), error);
	len = ft_strlen(pathToMap);
	if (!check_extension(pathToMap, len))
		error = 1;
	if (dup_map(map_fd) != 0)
		error = -1;
	output_validation(error, pathToMap);
	return (error);
}
