/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:00:40 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/11 22:20:54 by chguerre         ###   ########.fr       */
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
#endif // PLAYER_H
