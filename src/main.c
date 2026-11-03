/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:17 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/03 18:23:16 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl_fd("Please specify the map", 1);
	(void)av;
}
