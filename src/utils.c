/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:59:12 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/07 19:21:04 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	clear_paths(t_game *game)
{
	if (game->screen.path != NULL)
	{
		free(game->screen.path);
		game->screen.path = NULL;
	}
	if (game->w_north.path != NULL)
	{
		free(game->w_north.path);
		game->w_north.path = NULL;
	}
	if (game->w_south.path != NULL)
	{
		free(game->w_south.path);
		game->w_south.path = NULL;
	}
	if (game->w_west.path != NULL)
	{
		free(game->w_west.path);
		game->w_west.path = NULL;
	}
	if (game->w_est.path != NULL)
	{
		free(game->w_est.path);
		game->w_est.path = NULL;
	}
}

void	clear_images(t_game *game)
{
	if (game->screen.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->screen.img_ptr);
		game->screen.img_ptr = NULL;
	}
	if (game->w_north.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->w_north.img_ptr);
		game->w_north.img_ptr = NULL;
	}
	if (game->w_south.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->w_south.img_ptr);
		game->w_south.img_ptr = NULL;
	}
	if (game->w_west.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->w_west.img_ptr);
		game->w_west.img_ptr = NULL;
	}
	if (game->w_est.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->w_est.img_ptr);
		game->w_est.img_ptr = NULL;
	}
}

int	fill_path_img(t_img *img, char *path)
{
	char	*path_img;
	if (!path)
	{
		ft_putendl_fd("Error\npath (null)", 2);
		return (1);
	}
	path_img = ft_strdup(path);
	if (!path_img)
	{
		ft_putendl_fd("Error\nft_strdup(path) in fill path.", 2);
		return (1);
	}
	if (img->path != NULL)
		free(img->path);
	img->path = path_img;
	return (0);
}
