/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:23:35 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 17:23:35 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	orientation;
	double	rot_speed;
	double	move_speed;
	bool	key_w;
	bool	key_s;
	bool	key_a;
	bool	key_d;
	bool	key_rigth;
	bool	key_left;
}			t_player;

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
	int			map_fd;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		*path_to_map;
	int			count_lines;
	int			max_length;
	t_player	player;

	t_img		screen;
	t_img		w_north;
	t_img		w_south;
	t_img		w_est;
	t_img		w_west;
}			t_game;
#endif
