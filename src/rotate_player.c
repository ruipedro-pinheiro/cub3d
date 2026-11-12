/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ch <chguerre@42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:28:46 by ch                #+#    #+#             */
/*   Updated: 2026/11/12 17:30:18 by ch               ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	handle_rotation(t_player *p)
{
	double	cos_rot;
	double	sin_rot;
	double	old_dir_x;
	double	old_plane_x;

	if (!p || (!p->key_left && !p->key_rigth) || (p->key_left && p->key_rigth))
		return ;

	if (p->key_left)
	{
		cos_rot = cos(-p->rot_speed);
		sin_rot = sin(-p->rot_speed);
		ft_putendl_fd("turn to left", 2);
	}
	if (p->key_rigth)
	{
		cos_rot = cos(p->rot_speed);
		sin_rot = sin(p->rot_speed);
		ft_putendl_fd("turn to rigth", 2);
	}
	old_dir_x = p->dir_x;
	p->dir_x = old_dir_x * cos_rot - p->dir_y * sin_rot;
	p->dir_y = old_dir_x * sin_rot + p->dir_y * cos_rot;
	old_plane_x = p->plane_x;
	p->plane_x = old_plane_x * cos_rot - p->plane_y * sin_rot;
	p->plane_y = old_plane_x * sin_rot + p->plane_y * cos_rot;
}