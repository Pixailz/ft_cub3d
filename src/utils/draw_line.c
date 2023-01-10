/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:13:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 16:12:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_line(void *mlx_ptr, void *win_ptr, t_pos begin, t_pos end, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	dprintf(DEBUG_FD, "begin.x[%.2f] begin.y[%.2f] end.x[%.2f] end.y[%.2f]", begin.x, begin.y, end.x, end.y);
	while (pixels)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, begin.x, begin.y, color);
		begin.x += delta_x;
		begin.y += delta_y;
		pixels--;
	}
}
