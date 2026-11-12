/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 00:09:28 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/10 23:14:38 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
/*
#define MINISCALE 20
#define MINI_OFFSET_X 500
#define MINI_OFFSET_Y 200

unsigned int	select_color(char c, char orientation)
{
	if (c == '1')
		return (0xFFFFFF);
	else if (c == '0' || c == orientation)
		return (0x1E293B);
	return (0);
}

void	draw_square_tile(t_game *game, float pos_x, float pos_y,
		unsigned int color)
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (y < MINISCALE - 1)
	{
		x = 0;
		while (x < MINISCALE - 1)
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

float	*posicion_minimapa(t_game *game, float mini_pos[2])
{
	mini_pos[0] = (float)MINI_OFFSET_X + (game->player.pos_x
			* (float)MINISCALE);
	mini_pos[1] = (float)MINI_OFFSET_Y + (game->player.pos_y
			* (float)MINISCALE);
	return (mini_pos);
}
/*
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
	int mx;
	int my;
	int pos_x;
	int pos_y;
	float mini_pos[2];
	unsigned int color;
	(void)map;

	my = 0;
	while (my <= map_height - 1)
	{
		mx = 0;
		while (mx <= map_width - 1)
		{
			color = select_color(game->map[my][mx], game->player.orientation);

			pos_x = MINI_OFFSET_X + (mx * MINISCALE);
			pos_y = MINI_OFFSET_Y + (my * MINISCALE);
			draw_square_tile(game, pos_x, pos_y, MINISCALE, color);
			mx++;
		}
		my++;
	}
	posicion_minimapa(game, mini_pos);
	draw_square_tile(game, mini_pos[0],  mini_pos[1], 10, 0xFF0000);
}*/
