/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/09 12:33:16 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		error;

	ft_bzero(&game, sizeof(game));
	game.map = NULL;
	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./cub3d maps/map.cub", 2);
		return (1);
	}
	game.path_to_map = av[1];
	error = file_check(&game);
	if (error)
		return (safe_exit(&game, error));
	load_player_dt(&game);
	ft_putendl_fd("PLAYER DATA:", 1);
	ft_putendl_fd("pos_x: N/A\npos_y: N/A", 1);
	printf("dir_x: %f\ndir_y: %f", game.player.dir_x, game.player.dir_y);
	printf("plane_x: %f\nplane_y: %f\n", game.player.plane_x,
		game.player.plane_y);
	run_win_mlx(&game);
	return (safe_exit(&game, 0));
}
