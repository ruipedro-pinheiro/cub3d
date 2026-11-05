/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:03:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/04 18:05:12 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct    s_game {
    int      map_fd;
    void*    mlx_ptr;
    void*    win_ptr;
} t_game;
#endif
