/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerred <chguerre@student.42lausanne.ch>  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:00:22 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/09 11:34:11 by chguerre         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WIN_H
# define MLX_WIN_H

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
void	generate_minimap(t_game *game, int map_width, int map_height);

#endif // H_WIN
