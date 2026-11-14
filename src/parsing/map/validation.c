/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:11:16 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/13 19:39:58 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_pos(t_game *game, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (game->player.orientation != 0)
		{
			ft_putendl_fd("Error\nFound multiple player positions", 2);
			return (1);
		}
		game->player.pos_x = x + 0.5;
		game->player.pos_y = y + 0.5;
		game->player.orientation = c;
	}
	return (0);
}

int	check_valid_char(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (!ft_strchr("01NSWE ", map[i][j]))
				return (ft_putendl_fd("Error\nFond invalid char", 2), 1);
			if (check_pos(game, map[i][j], j, i))
				return (1);
		}
	}
	if (!game->player.orientation)
	{
		ft_putendl_fd("Error\nDidn't found player position", 2);
		return (1);
	}
	return (0);
}

int	check_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				if ((map[y][x + 1] == '\0' || map[y][x + 1] == ' ') || (map[y
						+ 1][x] == '\0' || map[y + 1][x] == ' ') || (map[y][x
						- 1] == '\0' || map[y][x - 1] == ' ') || (map[y
						- 1][x] == '\0' || map[y - 1][x] == ' '))
					return (ft_putendl_fd("Error\nMap not closed by walls", 2),
						1);
			}
		}
	}
	return (0);
}

int	validate_map(t_game *game)
{
	if (check_valid_char(game->map, game))
		return (1);
	if (check_map(game->map))
		return (1);
	return (0);
}
