/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:04:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/24 12:56:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print(int mode, void *ptr)
{
	if (!DEBUG)
		return ;
	if (mode == PARSE_RETURN_VALUE)
		ft_printf_fd(DEBUG_FD, "return_value=[%d]\n", *((int *)ptr));
	else if (mode == PARSE_LINE)
		debug_parse((char *)ptr);
	else if (mode == PARSE_EMPTY_LINE)
		ft_printf_fd(DEBUG_FD, "empty_line\n");
	else if (mode == PARSE_PARAMS_DONE)
		ft_printf_fd(DEBUG_FD, "params_done\n");
}
