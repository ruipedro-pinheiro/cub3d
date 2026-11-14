/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:53:57 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/12 16:13:17 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	validate(t_game *game)
{
	int	errno;

	errno = validate_headers(game);
	errno = validate_map(game);
	if (errno > 0)
		return (errno);
	return (0);
}
