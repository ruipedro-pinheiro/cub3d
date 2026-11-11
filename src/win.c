/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:48:16 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/11 23:44:31 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(safe_exit(game, 0));
	return (0);
}

void init_graphics(t_game *game)
{
	game->screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen.img_ptr)
		exit(safe_exit(game, 1));
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp, &game->screen.size_line, &game->screen.endian);
	if (load_textures(game) != 0)
		exit(safe_exit(game, 42));
}

int game_loop(t_game *game)
{
	update_movement(game);
	create_canvas(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img_ptr,	0, 0);
	return (0);
}

int	run_win_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub 3D - 42");
	init_graphics(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, (void *)handle_keypressed, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, (void *)handle_keyrelease, game);
	mlx_hook(game->win_ptr, 17, 9, (void *)close_window, game);
	mlx_loop_hook(game->mlx_ptr,(void *)game_loop, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

