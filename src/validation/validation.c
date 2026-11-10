/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:53:57 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/05 18:10:22 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

// TODO: Check headers first
/*
	What i would need:
	- Bool or flag for each item (C/F/NO/SO/WE/EA)
		C = Ceiling colour -> 3x 255
		F = Floor colour -> 3x 255
		NO = Path to NOrth wall texture ->  ./path_to_the_north_texture
		SO = Path to SOuth wall texture ->  ./path_to_the_south_texture
		WE = Path to WEst wall texture ->  ./path_to_the_west_texture
		EA = Path to EAst wall texture ->  ./path_to_the_east_texture
*/
int	validate_rgb(char *line)
{
	(void)line;
	return (0);
}

int	validate_texture_path(char *line)
{
	(void)line;
	return (0);
}

int	validate_headers(t_game *game)
{
	char	*line;
	int		i;
	int		j;
	int		errno;

	i = 0;
	while (game->map[i])
	{
		line = game->map[i];
		j = 0;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[0] == 'C' || line[0] == 'F')
			errno = validate_rgb(line);
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
			errno = validate_texture_path(line);
		else if (line[0] == '\n')
			i++;
		i++;
	}
	return (errno);
}

int	validate(t_game *game)
{
	int	errno;

	errno = validate_headers(game);
	if (errno > 0)
		return (errno);
	return (0);
}
