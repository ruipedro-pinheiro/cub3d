/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:03:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/05 17:34:16 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	char		orientation;
	int			rot_speed;
	int			move_speed;
}				t_player;

typedef struct s_img
{
	char		*path;
	void		*img_ptr;
	void		*addr;
	int			heigth;
	int			width;
	int			bpp;
	int			endian;
	int			size_line;
}				t_img;

typedef struct s_game
{
	int			map_fd;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		*path_to_map;
	int			cursorcreate_ca;
	int			count_lines;
	int			max_length;
	int			cursor;
	int			c_color[3];
	int			f_color[3];
	t_player	player;

	t_img		screen;
	t_img		w_north;
	t_img		w_south;
	t_img		w_est;
	t_img		w_west;
}				t_game;
#endif
