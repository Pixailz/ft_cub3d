/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:25:20 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 02:37:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_line	get_line(t_d_pos begin, t_d_pos end, t_int4 color)
{
	t_line	line;

	line.begin.x = begin.x;
	line.begin.y = begin.y;
	line.end.x = end.x;
	line.end.y = end.y;
	line.color = color;
	return (line);
}

void	draw_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = line.end.x - line.begin.x;
	delta_y = line.end.y - line.begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels != 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.begin.x, line.begin.y, line.color);
		line.begin.x += delta_x;
		line.begin.y += delta_y;
		pixels--;
	}
}
