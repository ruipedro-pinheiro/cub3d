/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:25:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/10 17:49:26 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

typedef enum e_header
{
	HEADER_NO,
	HEADER_SO,
	HEADER_WE,
	HEADER_EA,
	HEADER_C,
	HEADER_F,
	HEADER_INVALID
}	t_header;

int	validate_texture_path(t_game *game, char *line, int id);
int	validate_headers(t_game *game);
int	file_check(t_game *game);
int	validate(t_game *game);
