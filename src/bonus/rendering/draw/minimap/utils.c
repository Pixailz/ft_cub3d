/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:33:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 04:42:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

char	get_current_char_map(t_map map, t_i_pos pos)
{
	if (pos.x < MAX_DOF || pos.y < MAX_DOF || pos.x >= map.size.x + MAX_DOF || \
												pos.y >= map.size.y + MAX_DOF)
		return (VOID_CHAR);
	return (map.matrix[pos.y][pos.x]);
}

t_bool	opti_outof_mini_square(int px, int py)
{
	t_i_pos	max;

	max.x = MINI_CENTER_X + MINI_CIRCLE_RADIUS;
	max.y = MINI_CENTER_Y + MINI_CIRCLE_RADIUS;
	if (px >= 0 && py >= 0 && px <= max.x && py <= max.y)
		return (FALSE);
	return (TRUE);
}

t_bool	pos_is_in_circle(t_i_pos pos, t_i_pos counter, t_circle circle)
{
	unsigned int	x_x;
	unsigned int	y_y;
	unsigned int	pow_x;
	unsigned int	pow_y;

	x_x = pos.x + counter.x / 4;
	y_y = pos.y + counter.y;
	if (opti_outof_mini_square(x_x, y_y))
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
			if (pos_is_in_circle(pos, counter, circle))
			{
				dst->buff[tmp_point.x] = src->buff[tmp_point.y];
				dst->buff[tmp_point.x + 1] = src->buff[tmp_point.y + 1];
				dst->buff[tmp_point.x + 2] = src->buff[tmp_point.y + 2];
			}
			counter.x += 4;
		}
	}
}

void	draw_circle(t_circle circle, t_mlx_textures *text)
{
	float		counter;
	long int	x_x;
	long int	y_y;
	t_i_pos		point;

	counter = 0;
	while (counter < 360)
	{
		point.x = circle.radius * cos(counter * PI / 180);
		point.y = circle.radius * sin(counter * PI / 180);
		x_x = circle.center.x + point.x;
		y_y = circle.center.y + point.y;
		ft_put_pixel(x_x, y_y, &text->scene, circle.color);
		ft_put_pixel(x_x + 1, y_y, &text->scene, circle.color);
		ft_put_pixel(x_x - 1, y_y, &text->scene, circle.color);
		ft_put_pixel(x_x, y_y + 1, &text->scene, circle.color);
		ft_put_pixel(x_x, y_y - 1, &text->scene, circle.color);
		counter += 0.1;
	}
}
