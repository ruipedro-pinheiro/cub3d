/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:15:41 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/09 11:30:14 by chguerre         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/main.h>

int	load_player_dt(t_game *game)
{
	t_player	player;
	int			orientation;

	orientation = ON;
	if (orientation == ON)
	{
		player.dir_x = 0.0;
		player.dir_y = -1.0;
	}
	else if (orientation == OS)
	{
		player.dir_x = 0.0;
		player.dir_y = 1.0;
	}
	else if (orientation == OE)
	{
		player.dir_x = 1.0;
		player.dir_y = 0.0;
	}
	else if (orientation == OW)
	{
		player.dir_x = -1.0;
		player.dir_y = 0.0;
	}
	return (1);
}
