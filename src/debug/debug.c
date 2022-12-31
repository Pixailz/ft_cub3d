/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/29 15:23:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print(int mode, void *ptr)
{
	if (!DEBUG)
		return ;
	if (mode >= PARSE_RETURN_VALUE && mode <= PARSE_GET_MAP_SPLITTED)
		debug_print_parse(mode, ptr);
	ft_printf_fd(DEBUG_FD, "\n");
}
