/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:46:00 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 07:30:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_line_in_circle(t_mlx_texture *scene, t_line line, t_circle circle)
{
	double	delta_x;
	double	delta_y;
	t_i_pos	pos;
	int		pixels;

	delta_x = line.end.x - line.begin.x;
	delta_y = line.end.y - line.begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels != 0)
	{
		pos.x = line.begin.x;
		pos.y = line.begin.y;
		ft_put_pixel_in_circle(pos, scene, line.color, circle);
		line.begin.x += delta_x;
		line.begin.y += delta_y;
		pixels--;
	}
}

void	ft_put_pixel_in_circle(t_i_pos pos, t_mlx_texture *image, t_int4 color, t_circle circle)
{
	int		point;
	t_i_pos	zero;

	if (pos.x < 0 || pos.y < 0 || pos.x > image->len.x || pos.y > image->len.y)
		return ;
	zero.x = 0;
	zero.y = 0;
	if (pos_is_in_circle(pos, zero, circle))
		return ;
	point = pos.x * 4 + 4 * pos.y * image->len.x;
	image->buff[point + 2] = ft_int4_dcomp(color, 1);
	image->buff[point + 1] = ft_int4_dcomp(color, 2);
	image->buff[point] = ft_int4_dcomp(color, 3);
	return ;
}
