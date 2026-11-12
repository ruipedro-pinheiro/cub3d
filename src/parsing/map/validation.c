/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:11:16 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/12 16:15:24 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_top_bottom(char *line)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	while (line[len] == ' ')
		len--;
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
	{
		ft_putendl_fd("Not starting by 1 !", 2);
		return (1);
	}
	while (line[i] == '1' || line[i] == ' ')
		i++;
	if (line[i] != 1)
	{
		ft_putendl_fd(line, 2);
		ft_putendl_fd("Not ending by 1 !", 2);
		return (1);
	}
	return (0);
}

int	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = game->cursor;
	check_top_bottom(game->map[i]);
	while (game->map[i])
	{
		j = 0;
		if (game->map[i][0] == '\n')
			i++;
		while (game->map[i][j] == ' ')
			j++;
		if (game->map[i][j] != '1')
		{
			ft_putendl_fd("Not starting by 1", 2);
			ft_putendl_fd(game->map[i], 2);
			break ;
		}
		while (game->map[i][j] && (game->map[i][j] == '0' || game->map[i][j] == '1' || game->map[i][j] == ' '))
			j++;
		if (game->map[i][ft_strlen(game->map[i]) - 1] != '1')
		{
			ft_putendl_fd("Not ending by 1", 1);
			break ;
		}
		i++;
	}
	return (0);
}
