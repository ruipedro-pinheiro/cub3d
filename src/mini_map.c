/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 00:09:28 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/09 12:36:45 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

#define MINISCALE 20
#define MINI_OFFSET_X 500
#define MINI_OFFSET_Y 200

unsigned int	select_color(char c)
{
	if (c == '1')
		return (0xFFFFFF);
	else if (c == '0')
		return (0x1E293B);
	return (0);
}

void	draw_square_tile(t_game *game, int pos_x, int pos_y, int scale,
		unsigned int color)
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (y < scale - 1)
	{
		x = 0;
		while (x < scale - 1)
		{
			pixel_x = pos_x + x;
			pixel_y = pos_y + y;
			if (pixel_x >= 0 && pixel_x < WIDTH && pixel_y >= 0
				&& pixel_y < HEIGHT)
				put_pixel(pixel_x, pixel_y, color, game);
			x++;
		}
		y++;
	}
}

void	generate_minimap(t_game *game, int map_width, int map_height)
{
	int				mx;
	int				my;
	int				pos_x;
	int				pos_y;
	unsigned int	color;
	char			map[6][6] = {
	{'1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1'},
	};

	my = 0;
	while (my <= map_height - 1)
	{
		mx = 0;
		while (mx <= map_width - 1)
		{
			color = select_color(map[my][mx]);
			pos_x = MINI_OFFSET_X + (mx * MINISCALE);
			pos_y = MINI_OFFSET_Y + (my * MINISCALE);
			draw_square_tile(game, pos_x, pos_y, MINISCALE, color);
			mx++;
		}
		my++;
	}
}
