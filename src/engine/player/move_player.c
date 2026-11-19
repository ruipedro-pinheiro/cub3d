/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:25:09 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 17:25:09 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	move_up(t_player *p, char **map, double speed)
{
	if (map[(int)p->pos_y][(int)(p->pos_x + p->dir_x * speed)] != '1')
		p->pos_x += p->dir_x * speed;
	if (map[(int)(p->pos_y + p->dir_y * speed)][(int)p->pos_x] != '1')
		p->pos_y += p->dir_y * speed;
	return (0);
}

int	move_down(t_player *p, char **map, double speed)
{
	if (map[(int)p->pos_y][(int)(p->pos_x - p->dir_x * speed)] != '1')
		p->pos_x -= p->dir_x * speed;
	if (map[(int)(p->pos_y - p->dir_y * speed)][(int)p->pos_x] != '1')
		p->pos_y -= p->dir_y * speed;
	return (0);
}

int	move_rigth(t_player *p, char **map, double speed)
{
	if (map[(int)p->pos_y][(int)(p->pos_x + p->plane_x * speed)] != '1')
		p->pos_x += p->plane_x * speed;
	if (map[(int)(p->pos_y + p->plane_y * speed)][(int)p->pos_x] != '1')
		p->pos_y += p->plane_y * speed;
	return (0);
}

int	move_left(t_player *p, char **map, double speed)
{
	if (map[(int)p->pos_y][(int)(p->pos_x - p->plane_x * speed)] != '1')
		p->pos_x -= p->plane_x * speed;
	if (map[(int)(p->pos_y - p->plane_y * speed)][(int)p->pos_x] != '1')
		p->pos_y -= p->plane_y * speed;
	return (0);
}

int	move_player(t_player *p, char **map, t_game *game)
{
	if (p->key_w)
		move_up(p, map, p->move_speed * game->delta_time);
	if (p->key_s)
		move_down(p, map, p->move_speed * game->delta_time);
	if (p->key_d)
		move_rigth(p, map, p->move_speed * game->delta_time);
	if (p->key_a)
		move_left(p, map, p->move_speed * game->delta_time);
	return (0);
}
