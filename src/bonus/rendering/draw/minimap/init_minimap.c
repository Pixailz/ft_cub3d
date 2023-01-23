/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 14:43:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_circle(t_i_pos pos, t_int4 color, int r, t_mlx_textures *text)
{
	float		counter;
	long int	x_x;
	long int	y_y;
	t_i_pos		point;

	counter = 0;
	while (counter < 360)
	{
		point.x = r * cos(counter * PI / 180);
		point.y = r * sin(counter * PI / 180);
		x_x = pos.x + point.x;
		y_y = pos.y + point.y;
		ft_put_pixel(x_x, y_y, &text->scene, color);
		ft_put_pixel(x_x + 1, y_y, &text->scene, color);
		ft_put_pixel(x_x - 1, y_y, &text->scene, color);
		ft_put_pixel(x_x, y_y + 1, &text->scene, color);
		ft_put_pixel(x_x, y_y - 1, &text->scene, color);
		counter += 0.8;
	}
}

t_bool	pos_is_in_circle(t_i_pos pos, t_i_pos counter)
{
	unsigned int	x_x;
	unsigned int	y_y;
	unsigned int	pow_x;
	unsigned int	pow_y;

	x_x = pos.x + counter.x;
	y_y = pos.y + counter.y;
	pow_x = ((x_x / 4) - MINI_CENTER_X) * ((x_x / 4) - MINI_CENTER_X);
	pow_y = (y_y - MINI_CENTER_Y) * (y_y - MINI_CENTER_Y);
	return (pow_x + pow_y < MINI_TEXT_RADIUS);
}

void	text_to_buff_circle(t_i_pos pos, t_mlx_texture *src, t_mlx_texture *dst)
{
	int		begin_dst_y;
	t_i_pos	counter;

	counter.y = -1;
	while (++counter.y < (src->size_line / 4))
	{
		begin_dst_y = (pos.y + counter.y) * dst->size_line;
		counter.x = 0;
		while (counter.x < src->size_line)
		{
			if (pos_is_in_circle(pos, counter))
			{
				dst->buff[begin_dst_y + pos.x * 4 + counter.x] = \
				src->buff[counter.y * src->size_line + counter.x];
				dst->buff[begin_dst_y + pos.x * 4 + counter.x + 1] = \
				src->buff[counter.y * src->size_line + counter.x + 1];
				dst->buff[begin_dst_y + pos.x * 4 + counter.x + 2] = \
				src->buff[counter.y * src->size_line + counter.x + 2];
			}
			counter.x += 4;
		}
	}
}

void	init_mini_map(t_mlx_textures *text)
{
	t_i_pos	pos;

	pos.x = MINI_CENTER_X;
	pos.y = MINI_CENTER_Y;
	draw_circle(pos, MINI_EDGE_COLOR, MINI_CIRCLE_RADIUS, text);
}
