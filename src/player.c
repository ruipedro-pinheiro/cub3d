/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:41 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/09 12:17:59 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"


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
	t_player	player;
	int			orientation;

	(void)game;
	orientation = ON;
	set_player_dir(&player, orientation);
	set_player_plane(&player, orientation);
	return (1);
}
