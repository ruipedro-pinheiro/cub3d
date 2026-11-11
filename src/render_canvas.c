/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:02:18 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/11 23:48:57 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

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
	ft_bzero(game->screen.addr, HEIGHT * game->screen.size_line);

	render_texture(game, &game->w_north, 50, 200);
	render_texture(game, &game->w_south, 150, 200);
	render_texture(game, &game->w_est, 250, 200);
	render_texture(game, &game->w_west, 350, 200);
	generate_minimap(game, 6, 5);
//	draw_square(game, WIDTH / 2, 30, 60);
//	draw_square(game, WIDTH / 5, 60, 20);
}
