/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:01:30 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 16:02:45 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"


int	handle_keypressed(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 13 || keycode == 119)
		game->player.key_w = true;
	if (keycode == 0 || keycode == 97)
		game->player.key_a = true;
	if (keycode == 1 || keycode == 115)
		game->player.key_s = true;
	if (keycode == 2 || keycode == 100)
		game->player.key_d = true;
	if (keycode == 123 || keycode == 65361)
		game->player.key_left = true;
	if (keycode == 124 || keycode == 65363)
		game->player.key_rigth = true;
	if (keycode == 53 || keycode == 65307)
		exit(safe_exit(game, 0));
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 13 || keycode == 119)
		game->player.key_w = false;
	if (keycode == 0 || keycode == 97)
		game->player.key_a = false;
	if (keycode == 1 || keycode == 115)
		game->player.key_s = false;
	if (keycode == 2 || keycode == 100)
		game->player.key_d = false;
	if (keycode == 123 || keycode == 65361)
		game->player.key_left = false;
	if (keycode == 124 || keycode == 65363)
		game->player.key_rigth = false;
	if (keycode == 53 || keycode == 65307)
		exit(safe_exit(game, 0));
	return (0);
}
