/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:00:40 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/09 12:19:47 by chguerre         ###   ########.fr       */
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

int	load_player_dt(t_game *game);
#endif // PLAYER_H
