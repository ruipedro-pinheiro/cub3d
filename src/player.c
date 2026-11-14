/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:41 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/13 16:39:24 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	ft_strstrk(char *s1, char *s2)
{
	while (s1)
	{
		if (ft_strchr(s2, *s1))
			return (*s1);
		s1++;
	}
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
