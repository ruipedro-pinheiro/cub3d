/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:58:48 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/11 22:22:55 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	update_movement(t_game *game)
{
	double	move_speed;

	(void)move_speed;
	t_player *player = &game->player;

	if(player->key_w)
	{
		ft_putstr_fd("Forwards... W",2);
	}
}
