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

int	check_value(char *line, int *i, int *result, int j)
{
	int	value;

	value = 0;
	if (!ft_isdigit(line[*i]))
		return (ft_putendl_fd("Error\ninvalid RGB format", 2), 1);
	while (ft_isdigit(line[*i]))
	{
		value = value * 10 + (line[(*i)++] - '0');
		if (value > 255)
			return (ft_putendl_fd("Error\nRGB value over 255", 2), 1);
	}
	result[j] = value;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	if (j == 2 && line[*i] == '\0')
		return (0);
	if (j < 2 && line[*i] == ',')
		return ((*i)++, 0);
	return (ft_putendl_fd("Error\ninvalid RGB format", 2), 1);
}

int	validate_rgb(t_game *game, char *line, int id)
{
	int	i;
	int	count;
	int	*result;

	count = -1;
	i = 1;
	if (id == HEADER_F)
		result = game->f_color;
	else
		result = game->c_color;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (++count < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (check_value(line, &i, result, count))
			return (1);
	}
	printf("RGB: %d, %d, %d\n", result[0], result[1], result[2]);
	return (0);
}

static int	check_path(t_img *img)
{
	int	fd;

	if (!img->path || !img->path[0])
		return (ft_putendl_fd("Error\n couldn't setup wall textures", 2), 1);
	fd = open(img->path, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\ncouldn't open texture", 2), 1);
	close(fd);
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
	img->path = ft_strtrim(line + i, " \t");
	if (check_path(img))
		return (1);
	return (0);
}
