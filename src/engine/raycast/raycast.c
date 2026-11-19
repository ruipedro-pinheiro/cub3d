/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:00:35 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/17 13:23:03 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_sidestep(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	setup_dda(t_game *game, t_ray *ray)
{
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	set_sidestep(game, ray);
}

static int	check_limits(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map_height)
		return (1);
	else if (ray->map_x < 0 || ray->map_x >= ft_strlen(game->map[ray->map_y]))
		return (1);
	return (0);
}

void	dda(t_game *game, t_ray *ray)
{
	setup_dda(game, ray);
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_limits(game, ray) != 0)
			break ;
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
}

// TODO: add debugging mode and add 		// draw_plane(game, &ray, x);

void	cast_rays(t_game *game)
{
	int		x;
	t_ray	ray;

	x = -1;
	ft_bzero(&ray, sizeof(ray));
	while (++x < WIDTH)
	{
		ray.hit = 0;
		ray.camera_x = 2.0 * x / WIDTH - 1;
		ray.ray_dir_x = game->player.dir_x + game->player.plane_x
			* ray.camera_x;
		ray.ray_dir_y = game->player.dir_y + game->player.plane_y
			* ray.camera_x;
		dda(game, &ray);
		draw_walls(game, &ray, x);
		print_crosshair(game);
	}
}
