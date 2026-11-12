/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:41 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/10 11:14:24 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	*ft_strstrk(char *s1, char *s2)
{
	while (s1)
	{
		if (ft_strchr(s2, *s1))
			return (s1);
		s1++;
	}
	return (NULL);
}
/*
	n_player = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		player = ft_strstrk(game->map[i], "NSEW");
		if (player)
			n_player++;
		if (n_player != 0 || n_player != 1)
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Is more than only one player in the map", 2);
			return (1);
		}
		y = i;
		i++;
	}
	x = 0;
	while (game->map[y][x] != *(char)player)
		x++;*/

int	search_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->player.pos_y = y + 0.5;
	game->player.pos_x = x + 0.5;
	game->player.orientation = game->map[y][x];
	return (0);
}

static int	set_player_plane(t_player *player, const int dir)
{
	if (dir == ON)
		return (player->plane_x = 0.66, player->plane_y = 0.0, 1);
	if (dir == OS)
		return (player->plane_x = -0.66, player->plane_y = 0.0, 1);
	if (dir == OE)
		return (player->plane_x = 0.0, player->plane_y = 0.66, 1);
	if (dir == OW)
		return (player->plane_x = 0.0, player->plane_y = -0.66, 1);
	return (0);
}

static int	set_player_dir(t_player *player, const int dir)
{
	if (dir == ON)
		return (player->dir_x = 0.0, player->dir_y = -1.0, 1);
	if (dir == OS)
		return (player->dir_x = 0.0, player->dir_y = 1.0, 1);
	if (dir == OE)
		return (player->dir_x = 1.0, player->dir_y = 0.0, 1);
	if (dir == OW)
		return (player->dir_x = -1.0, player->dir_y = 0.0, 1);
	return (0);
}

int	load_player_dt(t_game *game)
{
	int	orientation;

	(void)game;
	orientation = OW;
	set_player_dir(&game->player, orientation);
	set_player_plane(&game->player, orientation);
	return (1);
}
