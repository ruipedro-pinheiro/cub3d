/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/04 17:27:48 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	main(int ac, char **av)
{
	int		error;
	t_data *data;

	data = NULL;
	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./cub3d maps/map.cub", 2);
		return (1);
	}
	error = validate_map(av[1]);
	if (error)
		return (error);
	run_win_mlx(data);
	return (0);
}
