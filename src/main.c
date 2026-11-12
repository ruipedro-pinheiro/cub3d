/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/10 21:40:05 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	print_data(t_game *game)
{
	printf("PLAYER DATA:\n");
	printf("pos_x: %f\npos_y: %f\n", game->player.pos_x, game->player.pos_y);
	printf("dir_x: %f\ndir_y: %f\n", game->player.dir_x, game->player.dir_y);
	printf("plane_x: %f\nplane_y: %f\n", game->player.plane_x,
		game->player.plane_y);
	printf("Orientacion: %c\n", game->player.orientation);
}

// TODO: Start struct t_game here;
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
	print_data(&game);
	run_win_mlx(&game);
	return (safe_exit(&game, 0));
}
