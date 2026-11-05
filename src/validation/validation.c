/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:53:57 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/05 18:04:45 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

//TODO: Check headers first
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

int	validate(t_game *game)
{
	char	*line;
	int		i;
	int		j;
	int		errno;

	i = 0;
	j = 0;
	line = game->map[i];
	while (game->map[i])
	{
		if (game->map[i][j] == 'C' || game->map[i][j] == 'F')
			errno = validate_rgb(line);
		else if (ft_strncmp(game->map[i], "NO", 2)
			|| ft_strncmp(game->map[i], "SO", 2)
			|| ft_strncmp(game->map[i], "WE", 2)
			|| ft_strncmp(game->map[i], "EA", 2))
			errno = validate_texture_path(line);
		else
			errno = 1;
		i++;
		j++;
	}
	if (errno)
		return (errno);
	return (0);
}
