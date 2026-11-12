/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:00:51 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 15:00:57 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

# define TEXTURE_NORTH "assets/textures/north.xpm"
# define TEXTURE_SOUTH "assets/textures/south.xpm"
# define TEXTURE_WEST "assets/textures/west.xpm"
# define TEXTURE_EST "assets/textures/est.xpm"
# define HEIGHT 1080
# define WIDTH 1920

int		run_win_mlx(t_game *game);
int		game_loop(t_game *game);
void	create_canvas(t_game *game);
// CLEANING FUNTIONS
void	clear_images(t_game *game);
void	clear_paths(t_game *game);
int		safe_exit(t_game *game, int code);
//
void	generate_minimap(t_game *game, int map_width, int map_height);

#endif // H_WIN
