/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:48:16 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/10 23:35:36 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	safe_exit(t_game *game, int code)
{
	clear_images(game);
	clear_paths(game);
	if (game->map != NULL)
	{
		ft_strfree(game->map);
		game->map = NULL;
	}
	if (game->mlx_ptr && game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	return (code);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit(safe_exit(game, 0));
	return (0);
}

int	handle_keypressed(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_printf("%\n", keycode);
	if (keycode == 13 || keycode == 119)
		ft_printf("TECLA PRESIONADA W: %d\n", keycode);
	if (keycode == 0 || keycode == 97)
		ft_printf("TECLA PRESIONADA A: %d\n", keycode);
	if (keycode == 1 || keycode == 115)
		ft_printf("TECLA PRESIONADA S: %d\n", keycode);
	if (keycode == 2 || keycode == 100)
		ft_printf("TECLA PRESIONADA S: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(safe_exit(game, 0));
	return (0);
}

int	run_win_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub 3D - 42");
	create_canvas(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, (void *)handle_keypressed, game);
	mlx_hook(game->win_ptr, 17, 9, (void *)close_window, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
