/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 23:31:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print_coord_checked(int x, int y, char **map)
{
	// to remove
	if (DEBUG && 1 == 0)
	{
		ft_printf_fd(DEBUG_FD, "(%d,%d;[%c]):\n", x, y, map[x][y]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x - 1][y - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x - 1][y]);
		ft_printf_fd(DEBUG_FD, "[%c]\n", map[x - 1][y + 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x][y - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x][y]);
		ft_printf_fd(DEBUG_FD, "[%c]\n", map[x][y + 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x + 1][y - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[x + 1][y]);
		ft_printf_fd(DEBUG_FD, "[%c]\n\n", map[x + 1][y + 1]);
	}
}
