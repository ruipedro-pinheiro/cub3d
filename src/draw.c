/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:42:52 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/07 20:43:53 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	char	*ptr_px;
	t_img	*img;

	img = &game->screen;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	ptr_px = (char *)img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)ptr_px = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	src = (char *)img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)src);
}
