/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:53:57 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/14 13:10:37 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	validate(t_game *game)
{
	int	errno;

	errno = validate_headers(game);
	if (errno != 0)
		return (errno);
	errno = validate_map(game);
	if (errno != 0)
		return (errno);
	return (0);
}
