/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:13:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 15:28:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_line(t_mlx *mlx, t_pos begin, t_pos end, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx->ptr, mlx->win_3d, begin.x, begin.y, color);
		begin.x += delta_x;
		begin.y += delta_y;
		pixels--;
	}
}
