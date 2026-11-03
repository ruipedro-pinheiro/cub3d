/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/03 16:13:26 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl_fd("Please give a cookie !", 2);
	(void)av;
	ft_putendl_fd("Hello there ! Welcom to cub3d", 1);
}
