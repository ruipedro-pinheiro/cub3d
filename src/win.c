/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:48:16 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/06 18:09:13 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
void	safe_exit(t_game *game, int code)
{
	clear_images(game);
	if(game->map != NULL)
		ft_strfree(game->map);
	if(game->mlx_ptr || game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if(game->mlx_ptr)
	free(game->mlx_ptr);
	exit(code);
}
// TODO free all things in close windows and ESC
int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	safe_exit(game, 1);
	return (0);
}

int	handle_keypressed(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	printf("La tecla presionada es keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
	{
		safe_exit(game, 1);
	}
	return (0);
}

int	run_win_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "Cub 3D - 42");
	create_canvas(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, (void *)handle_keypressed, game);
	mlx_hook(game->win_ptr, 17, 9, (void *)close_window, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
