/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/04 13:45:58 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

// I've decided to return specific errors specifying why the map is not valid.
// There's still not real map validation from the rules but only basic checks
// 0 = good/no errors
//-1 = doesn't exist
// 1 = not valid (any rules that are invalid following subject) TODO:

void	output_validation(int error, char *pathToMap)
{
	if (error == 1)
		(ft_putstr(pathToMap), ft_putendl_fd(" is not valid", 2));
	if (error == -1)
		(ft_putstr(pathToMap), ft_putendl_fd(" does not exist", 2));
}

bool	check_extension(char *str, int len)
{
	if (str[len - 1] == 'b' && str[len - 2] == 'u' && str[len - 3] == 'c'
		&& str[len - 4] == '.')
		return (true);
	return (false);
}

int	validate_map(char *pathToMap)
	{
	int		len;
	int		map_fd;
	int		error;

	error = 0;
	map_fd = open(pathToMap, O_RDONLY);
	if (map_fd == -1)
		return (output_validation(error = -1, pathToMap), error);
	len = ft_strlen(pathToMap);
	if (!check_extension(pathToMap, len))
		error = 1;
	output_validation(error, pathToMap);
	return (error);
}

int	main(int ac, char **av)
{
	int	error;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./cub3d maps/map.cub", 2);
		return (1);
	}
	error = validate_map(av[1]);
	if (!error)
		return (error);
}
