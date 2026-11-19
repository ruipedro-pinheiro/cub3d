/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:23:35 by ch                #+#    #+#             */
/*   Updated: 2026/11/17 20:14:58 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdbool.h>

typedef struct s_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	dx;
	double	dy;
	double	inc_x;
	double	inc_y;
	double	curr_x;
	double	curr_y;
	int		step;
}			t_line;

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
	double		last_time;
	double		delta_time;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**config;
	char		**map;
	int			map_height;
	char		*path_to_map;
	int			cursorcreate_ca;
	int			c_color[3];
	int			f_color[3];
	int			map_fd;
	t_player	player;
	t_img		screen;
	t_img		w_north;
	t_img		w_south;
	t_img		w_est;
	t_img		w_west;
}				t_game;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	t_img	*texture;
}	t_ray;

#endif
