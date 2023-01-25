/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:47:06 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 11:26:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	opti_outof_mini_square(int px, int py, t_circle circle)
{
	t_i_pos	max;

	max.x = circle.center.x + circle.radius;
	max.y = circle.center.y + circle.radius;
	if (px >= 0 && py >= 0 && px <= max.x && py <= max.y)
		return (FALSE);
	return (TRUE);
}

t_bool	pos_is_in_circle(t_i_pos pos, int c_x, int c_y, t_circle circle)
{
	unsigned int	x_x;
	unsigned int	y_y;
	unsigned int	pow_x;
	unsigned int	pow_y;

	x_x = pos.x + c_x;
	y_y = pos.y + c_y;
	if (opti_outof_mini_square(x_x, y_y, circle))
		return (FALSE);
	x_x -= circle.center.x;
	y_y -= circle.center.y;
	pow_x = (x_x) * (x_x);
	pow_y = (y_y) * (y_y);
	return (sqrt(pow_x + pow_y) < circle.radius - MINI_EDGE_TRESH);
}

void	text_to_buff_circle(t_i_pos pos, t_mlx_texture *src, t_mlx_texture *dst, t_circle circle)
{
	int		begin_dst_y;
	int		begin_src_y;
	t_i_pos	tmp_point;
	t_i_pos	counter;

	counter.y = -1;
	while (++counter.y < src->size_line / 4)
	{
		begin_dst_y = (pos.y + counter.y) * dst->size_line;
		begin_src_y = counter.y * src->size_line;
		counter.x = 0;
		while (counter.x < src->size_line)
		{
			tmp_point.x = begin_dst_y + pos.x * 4 + counter.x;
			tmp_point.y = begin_src_y + counter.x;
			if (pos_is_in_circle(pos, counter.x / 4, counter.y, circle))
			{
				dst->buff[tmp_point.x] = src->buff[tmp_point.y];
				dst->buff[tmp_point.x + 1] = src->buff[tmp_point.y + 1];
				dst->buff[tmp_point.x + 2] = src->buff[tmp_point.y + 2];
			}
			counter.x += 4;
		}
	}
}

void	put_line_in_circle(t_mlx_texture *scene, t_line line, t_circle circle)
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

	if (pos.x < 0 || pos.y < 0 || pos.x > image->len.x || pos.y > image->len.y)
		return ;
	// if (!pos_is_in_circle(pos, 0, 0, circle))
	// 	return ;
	point = pos.x * 4 + 4 * pos.y * image->len.x;
	image->buff[point] = ft_int4_dcomp(color, 0);
	image->buff[point + 1] = ft_int4_dcomp(color, 1);
	image->buff[point + 2] = ft_int4_dcomp(color, 2);
	return ;
}
