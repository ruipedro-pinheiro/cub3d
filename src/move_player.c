/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:58:48 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/11 23:35:28 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	update_movement(t_game *game)
{
	double	m_speed;
	double	colision;

	m_speed  = 0.02;
	colision = 0.2;
	t_player *p = &game->player;

	if(p->key_w)
	{
		if(game->map[(int)p->pos_y][(int)(p->pos_x + p->dir_x * m_speed - colision)] != '1')
			p->pos_x += p->dir_x * m_speed;
		if(game->map[(int)(p->pos_y + p->dir_y * m_speed - colision)][(int)p->pos_x] != '1')
			p->pos_y += p->dir_y * m_speed;
	}
	if(p->key_s)
	{
		if(game->map[(int)p->pos_y][(int)(p->pos_x - p->dir_x * m_speed + colision)] != '1')
			p->pos_x -= p->dir_x * m_speed;
		if(game->map[(int)(p->pos_y - p->dir_y * m_speed + colision)][(int)p->pos_x] != '1')
			p->pos_y -= p->dir_y * m_speed;
	}
}
