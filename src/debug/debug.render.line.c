/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.render.line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:24:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 21:59:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print_line_pos(t_line *line)
{
	dprintf(DEBUG_FD, "line.begin (x:%.2f,y:%.2f) | line.end (x:%.2f,y:%.2f)", \
			line->begin.x, line->begin.y, \
			line->end.x, line->end.y);
}
