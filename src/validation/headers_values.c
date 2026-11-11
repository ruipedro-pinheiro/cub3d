/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:47:32 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/11 11:02:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	validate_rgb(char *line)
{
	(void)line;
	return (0);
}

int	validate_texture_path(t_game *game, char *line, int id)
{
	int		i;
	t_img	*img;

	i = 2;
	img = NULL;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (id == HEADER_NO)
		img = &game->w_north;
	else if (id == HEADER_SO)
		img = &game->w_south;
	else if (id == HEADER_WE)
		img = &game->w_west;
	else if (id == HEADER_EA)
		img = &game->w_est;
	else
		return (1);
	img->path = ft_strdup(line + i);
	if (!img->path || !img->path[0])
		return (ft_putendl_fd(FG_BOLD_RED "Error\n couldn't setup wall textures"
				FG_DEFAULT, 2), 1);
	return (0);
}
