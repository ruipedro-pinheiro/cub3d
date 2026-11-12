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

#include "../inc/main.h"

int	move_up(t_player *p, char **map, double speed, double pad)
{
	if (map[(int)p->pos_y][(int)(p->pos_x + p->dir_x * (speed + pad))] != '1')
		p->pos_x += p->dir_x * speed;
	if (map[(int)(p->pos_y + p->dir_y * (speed + pad))][(int)p->pos_x] != '1')
		p->pos_y += p->dir_y * speed;
	return (0);
}

int	move_down(t_player *p, char **map, double speed, double pad)
{
	if (map[(int)p->pos_y][(int)(p->pos_x - p->dir_x * (speed + pad))] != '1')
		p->pos_x -= p->dir_x * speed;
	if (map[(int)(p->pos_y - p->dir_y * (speed + pad))][(int)p->pos_x] != '1')
		p->pos_y -= p->dir_y * speed;
	return (0);
}

int	move_rigth(t_player *p, char **map, double speed, double pad)
{
	if (map[(int)p->pos_y][(int)(p->pos_x + p->plane_x * (speed + pad))] != '1')
		p->pos_x += p->plane_x * speed;
	if (map[(int)(p->pos_y + p->plane_y * (speed + pad))][(int)p->pos_x] != '1')
		p->pos_y += p->plane_y * speed;
	return (0);
}

int	move_left(t_player *p, char **map, double speed, double pad)
{
	if (map[(int)p->pos_y][(int)(p->pos_x - p->plane_x * (speed + pad))] != '1')
		p->pos_x -= p->plane_x * speed;
	if (map[(int)(p->pos_y - p->plane_y * speed - pad)][(int)p->pos_x] != '1')
		p->pos_y -= p->plane_y * speed;
	return (0);
}

int	move_player(t_player *p, char **map)
{
	if (p->key_w)
		move_up(p, map, p->move_speed, 0.30);
	if (p->key_s)
		move_down(p, map, p->move_speed, 0.30);
	if (p->key_d)
		move_rigth(p, map, p->move_speed, 0.30);
	if (p->key_a)
		move_left(p, map, p->move_speed, 0.30);
	return (0);
}

void	update_movement(t_game *game)
{
	t_player	*p;

	p = &game->player;
	move_player(p, game->map);
}
