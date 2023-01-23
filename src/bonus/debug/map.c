/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 07:32:26 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	debug_print_coord_checked(t_i_pos pos, char **map)
{
	if (DEBUG && VERBOSE >= 2)
	{
		ft_printf_fd(DEBUG_FD, "(%d,%d;[%c]):\n", pos.y, pos.x, \
															map[pos.y][pos.x]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y - 1][pos.x - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y - 1][pos.x]);
		ft_printf_fd(DEBUG_FD, "[%c]\n", map[pos.y - 1][pos.x + 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y][pos.x - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y][pos.x]);
		ft_printf_fd(DEBUG_FD, "[%c]\n", map[pos.y][pos.x + 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y + 1][pos.x - 1]);
		ft_printf_fd(DEBUG_FD, "[%c]", map[pos.y + 1][pos.x]);
		ft_printf_fd(DEBUG_FD, "[%c]\n\n", map[pos.y + 1][pos.x + 1]);
	}
}
