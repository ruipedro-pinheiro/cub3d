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
	ON,
	OS,
	OE,
	OW
};

int		load_player_dt(t_game *game);
int		handle_keypressed(int keycodde, void *param);
int		handle_keyrelease(int keycodde, void *param);
void	update_movement(t_game *game);
void	handle_rotation(t_player *p);
#endif // PLAYER_H
