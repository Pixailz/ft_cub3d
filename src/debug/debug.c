/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 15:07:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print(int mode, void *ptr)
{
	if (!DEBUG)
		return ;
	if (mode == ERROR_PRINT_ERRN)
		debug_print_error(mode);
	else if (mode >= PARSE_RETURN_VALUE && mode <= PARSE_GET_MAP_SURROUDED)
		debug_print_parse(mode, ptr);
	else if (mode >= RENDER_SCREEN_SIZE && mode <= RENDER_PLAYER)
		debug_print_render(mode, ptr);
	ft_printf_fd(DEBUG_FD, "\n");
}
