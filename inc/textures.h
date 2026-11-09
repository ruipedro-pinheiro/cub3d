/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:03:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/07 20:46:41 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef textures_H
# define textures_H

void			put_pixel(int x, int y, int color, t_game *game);
unsigned int	get_pixel(t_img *img, int x, int y);

#endif
