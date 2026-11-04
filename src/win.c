/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:48:16 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/04 20:49:15 by chguerre         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int handle_keypressed(void *param)
{
	t_data	*data;

	data = (t_data *)&param;
	printf("La tecla presionada es keycode: %d", data->keycode);
	if (data->keycode == 53)
    {
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	return (0);
}

int run_win_mlx(t_data* data)
{
	data = malloc(sizeof(t_data));
	if(!data)
	{
		perror("malloc");
		return (0);
	}
	data->mlx_ptr = mlx_init();
	if(!data->mlx_ptr)
	{
		free(data);
		data = NULL;
		return (0);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "Cub 3D - 42");
	mlx_hook(data->win_ptr, 2, 1L << 0, (void *)handle_keypressed, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

