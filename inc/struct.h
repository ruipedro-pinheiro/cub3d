/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:03:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/07 17:42:06 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	char	*path;
	void	*img_ptr;
	void	*addr;
	int		heigth;
	int		width;
	int		bpp;
	int		endian;
	int		size_line;
}			t_img;

typedef struct s_game
{
	int		map_fd;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	*path_to_map;
	int		count_lines;
	int		max_length;

	t_img	screen;
	t_img	w_north;
	t_img	w_south;
	t_img	w_est;
	t_img	w_west;
}			t_game;
#endif
