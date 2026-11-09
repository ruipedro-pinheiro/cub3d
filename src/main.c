/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/07 20:48:58 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

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
	error = validate_map(&game);
	if (error)
		return (ft_strfree(game.map), error);
	run_win_mlx(&game);
	return (safe_exit(&game, 0));
}
