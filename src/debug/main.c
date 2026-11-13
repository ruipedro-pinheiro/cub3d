/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:11:25 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/13 16:21:37 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_data(t_game *game)
{
	int	x;

	x = -1;
	ft_putendl_fd("=== CONFIG ===", 2);
	while (game->config[++x] != NULL)
	{
		ft_putstr_fd("|> ", 2);
		ft_putendl_fd(game->config[x], 2);
	}
	x = -1;
	ft_putendl_fd("\n=== MAP ===", 2);
	while (game->map[++x] != NULL)
	{
		ft_putnbr_fd(x, 2);
		ft_putstr_fd("|> ", 2);
		ft_putendl_fd(game->map[x], 2);
	}
	printf("PLAYER DATA:\n");
	printf("pos_x: %f\npos_y: %f\n", game->player.pos_x, game->player.pos_y);
	printf("dir_x: %f\ndir_y: %f\n", game->player.dir_x, game->player.dir_y);
	printf("plane_x: %f\nplane_y: %f\n", game->player.plane_x,
		game->player.plane_y);
	printf("Orientacion: %c\n", game->player.orientation);
}
