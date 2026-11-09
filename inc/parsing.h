/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:25:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/07 18:44:18 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		validate_map(t_game *game);
int		validate(t_game *game);
int		fill_path_img(t_img *img, char *path);
