/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 19:36:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	debug_print(int mode, void *ptr)
{
	if (!DEBUG)
		return ;
	if (mode == ERROR_PRINT_ERRN)
		debug_print_error(mode, ptr);
	else if (mode >= PARSE_RETURN_VALUE && mode <= PARSE_MAP_SIZE)
		debug_print_parse(mode, ptr);
	else if (mode >= RENDER_SCREEN_SIZE && mode <= RENDER_LINE)
		debug_print_render(mode, ptr);
	else if (mode >= RAY_HORIZONTAL && mode <= RAY_VERTICAL)
		debug_print_ray(mode, ptr);
}
