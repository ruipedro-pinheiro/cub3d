/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:39:33 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 16:39:38 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

enum	e_orient
{
	ON = 1,
	OS,
	OE,
	OW
};

int			load_player_dt(t_game *game);
int			handle_keypressed(int keycodde, void *param);
int			handle_keyrelease(int keycodde, void *param);
void		handle_rotation(t_player *p, t_game *game);
void		update_movement(t_game *game);
int			move_player(t_player *p, char **map, t_game *game);
void		draw_line(t_game *game, t_line *line, int color);

#endif // PLAYER_H
