/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:49:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/11/11 10:52:56 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define FG_DEFAULT "\033[39m"
# define BG_DEFAULT "\033[49m"

/*	===	FOREGROUND	=== */
# define FG_RED "\033[31m"
# define FG_BOLD_RED "\033[1;31m"
# define FG_GREEN "\033[32m"
# define FG_BOLD_GREEN "\033[1;32m"
# define FG_YELLOW "\033[33m"
# define FG_BOLD_YELLOW "\033[1;33m"
# define FG_BLUE "\033[34m"
# define FG_BOLD_BLUE "\033[1;34m"
# define FG_MAGENTA "\033[35m"
# define FG_BOLD_MAGENTA "\033[1;35m"
# define FG_WHITE "\033[37m"
# define FG_BOLD_WHITE "\033[1;37m"
# define FG_CYAN "\033[36m"
# define FG_BOLD_CYAN "\033[1;36m"

/*	===BACKGROUND	=== */
# define BG_RED "\033[41m"
# define BG_BLACK "\033[40m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"

#endif /* COLORS_H */
