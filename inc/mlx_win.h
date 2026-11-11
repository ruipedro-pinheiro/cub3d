/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerred <chguerre@student.42lausanne.ch>  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:00:22 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/04 21:02:22 by chguerre         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

# define TEXTURE_NORTH "assets/textures/north.xpm"
# define TEXTURE_SOUTH "assets/textures/south.xpm"
# define TEXTURE_WEST "assets/textures/west.xpm"
# define TEXTURE_EST "assets/textures/est.xpm"
# define HEIGHT 600
# define WIDTH 800

int		fill_path_img(t_img *img, char *path);
int		run_win_mlx(t_game *game);
int		handle_keypressed(int keycodde, void *param);
void	create_canvas(t_game *game);
// CLEANING FUNTIONS
void	clear_images(t_game *game);
void	clear_paths(t_game *game);
int		safe_exit(t_game *game, int code);
//
#endif // H_WIN
