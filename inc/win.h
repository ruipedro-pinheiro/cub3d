/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerred <chguerre@student.42lausanne.ch>  +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:00:22 by chguerre          #+#    #+#             */
/*   Updated: 2026/11/04 21:02:22 by chguerre         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_WIN
#define H_WIN

typedef struct s_data {
    void* mlx_ptr;
    void* win_ptr;
    int keycode;
} t_data;

int run_win_mlx(t_data* data);
int handle_keypressed(void* param);

#endif // H_WIN
