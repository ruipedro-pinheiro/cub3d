/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:02:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/06 16:23:19 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
void	clear_images(t_game *game);

void	init_textures(t_game *game)
{
	game->w_north->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, TEXTURE_NORTH, 64, 64);
	game->w_south->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, TEXTURE_SOUTH, 64, 64); 
	game->w_est->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, TEXTURE_EST, 64, 64);
	game->w_west->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, TEXTURE_WEST, 64, 64);
}

void	create_canvas(t_game *game)
{
	game->screen->img_ptr =mlx_new_image(game->mlx_ptr, 400, 400);
	if(!game->screen->img_ptr)
		return ;
	game->screen->addr =  mlx_get_data_addr(game->screen->img_ptr, game->screen->bpp, game->screen->size_line, game->screen->endian);
	
	init_textures(game);
}