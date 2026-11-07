/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:02:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/07 19:20:26 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static int init_img(t_img *img, void *mlx_ptr, char *path)
{
	if(fill_path_img(img, path) == 1)
		return(1);
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, img->path,
			&img->width, &img->heigth);
	if (img->img_ptr == NULL)
		return (perror("Error loading NORTH"), 1);
	return (0);
}

int	load_textures(t_game *game)
{
	if (init_img(&game->w_north, game->mlx_ptr, TEXTURE_NORTH))
		return (1);
	if (init_img(&game->w_south, game->mlx_ptr, TEXTURE_SOUTH))
		return (1);
	if (init_img(&game->w_est, game->mlx_ptr, TEXTURE_EST))
		return (1);
	if (init_img(&game->w_west, game->mlx_ptr, TEXTURE_WEST))
		return (1);
	return (0);
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	char	*ptr_px;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	ptr_px = (char *)game->screen.addr + (y * game->screen.size_line + x * 4);
	*(unsigned int *)ptr_px = color;
}

void	draw_square(t_game *game, int x, int y, int size)
{
	int	i;
	int	color;

	color = 0x00FF00;
	i = 0;
	while (i < size)
		put_pixel(x + i++, y, color, game);
	i = 0;
	while (i < size)
		put_pixel(x, y + i++, color, game);
	i = 0;
	while (i < size)
		put_pixel(x + size, y + i++, color, game);
	i = 0;
	while (i < size)
		put_pixel(x + i++, y + size, color, game);
	return ;
}

void	create_canvas(t_game *game)
{
	game->screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen.img_ptr)
		safe_exit(game, 1);
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp, &game->screen.size_line, &game->screen.endian);
	if (load_textures(game) != 0)
		safe_exit(game, 42);
	draw_square(game, WIDTH / 2, 30, 60);
	draw_square(game, WIDTH / 5, 60, 20);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img_ptr,
		0, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->w_est.img_ptr,
		200, 200);
}
