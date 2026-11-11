/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:08:06 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/11 22:28:11 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"


int	handle_keypressed(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("%\n", keycode);
	if (keycode == 13 || keycode == 119)
	{
		game->player.key_w = true;
		ft_printf("TECLA PRESIONADA W: %d\n", keycode);
	}
	if (keycode == 0 || keycode == 97)
	{
		game->player.key_a = true;
		ft_printf("TECLA PRESIONADA A: %d\n", keycode);
	}

	if (keycode == 1 || keycode == 115)
	{
		game->player.key_s = true;
		ft_printf("TECLA PRESIONADA S: %d\n", keycode);
	}
	if (keycode == 2 || keycode == 100)
		{
			game->player.key_d = true;
			ft_printf("TECLA PRESIONADA D: %d\n", keycode);}
	if (keycode == 53 || keycode == 65307)
		exit(safe_exit(game, 0));
	return (0);
}
int	handle_keyrelease(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("%\n", keycode);
	if (keycode == 13 || keycode == 119)
	{
		game->player.key_w = false;
		ft_printf("RELEASE W: %d\n", keycode);
	}
	if (keycode == 0 || keycode == 97)
	{
		game->player.key_a = false;
		ft_printf("RELEASE A: %d\n", keycode);
	}

	if (keycode == 1 || keycode == 115)
	{
		game->player.key_s = false;
		ft_printf("RELEASE S: %d\n", keycode);
	}
	if (keycode == 2 || keycode == 100)
		{
			game->player.key_d = false;
			ft_printf("RELEASE D: %d\n", keycode);}
	if (keycode == 53 || keycode == 65307)
		exit(safe_exit(game, 0));
	return (0);
}
