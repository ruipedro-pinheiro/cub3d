/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:02:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/08 01:15:24 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static int	init_img(t_img *img, void *mlx_ptr, char *path)
{
	if (fill_path_img(img, path) == 1)
		return (1);
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, img->path, &img->width,
			&img->heigth);
	if (img->img_ptr == NULL)
	{
		ft_putstr_fd("Error\nFailed loading texture in path -> ", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
			&img->endian);
	if (!img->addr)
	{
		ft_putstr_fd("Error\nFailed loading img->addr", 2);
		ft_putendl_fd(path, 2);
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	if (init_img(&game->w_north, game->mlx_ptr, game->w_north.path))
		return (1);
	if (init_img(&game->w_south, game->mlx_ptr, game->w_south.path))
		return (1);
	if (init_img(&game->w_est, game->mlx_ptr, game->w_est.path))
		return (1);
	if (init_img(&game->w_west, game->mlx_ptr, game->w_est.path))
		return (1);
	return (0);
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

static void	render_texture(t_game *game, t_img *img, int posx, int posy)
{
	int				x;
	int				y;
	unsigned int	color;

	if (posx < 0 || posx >= WIDTH || posy < 0 || posy >= HEIGHT)
		return ;
	y = 0;
	while (y < img->heigth)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel(img, x, y);
			if (color != 0xff000000)
				put_pixel(posx + x, posy + y, color, game);
			x++;
		}
		y++;
	}
}

void	create_canvas(t_game *game)
{
	game->screen.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen.img_ptr)
		exit(safe_exit(game, 1));
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp, &game->screen.size_line, &game->screen.endian);
	if (load_textures(game) != 0)
		exit(safe_exit(game, 42));
	render_texture(game, &game->w_north, 50, 200);
	render_texture(game, &game->w_south, 150, 200);
	render_texture(game, &game->w_est, 250, 200);
	render_texture(game, &game->w_west, 350, 200);
	generate_minimap(game, 6, 6);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img_ptr,
		0, 0);
}
//	draw_square(game, WIDTH / 2, 30, 60);
//	draw_square(game, WIDTH / 5, 60, 20);
