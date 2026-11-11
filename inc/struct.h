/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/11/11 22:07:21 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	char	orientation;
	int		rot_speed;
	int		move_speed;
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
