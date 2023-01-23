/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 11:35:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	text_to_buff(t_i_pos pos, t_mlx_texture *src, t_mlx_texture *dst)
{
	int		begin_src_y;
	int		begin_dst_y;
	t_i_pos	counter;

	counter.y = 0;
	while (counter.y < (src->size_line / 4))
	{
		begin_dst_y = (pos.y + counter.y) * dst->size_line;
		begin_src_y = counter.y * src->size_line;
		counter.x = 0;
		while (counter.x < src->size_line)
		{
			dst->buff[begin_dst_y + pos.x * 4 + counter.x] = \
			src->buff[begin_src_y + counter.x];
			counter.x++;
		}
		counter.y++;
	}
}

/*

*/

t_i_pos	*draw_circle(t_i_pos pos, t_int4 color, int r, t_mlx *mlx)
{
	float			counter;
	int				point_id;
	static t_i_pos	point[450] = {0};

	counter = 0;
	while (counter < 360)
	{
		point_id = (int)counter;
		point[point_id].x = r * cos(counter * PI / 180);
		point[point_id].y = r * sin(counter * PI / 180);
		ft_put_pixel(pos.x + point[point_id].x, pos.y + point[point_id].y, \
											&mlx->textures.scene, color);
		ft_put_pixel((pos.x + 1) + point[point_id].x, \
						pos.y + point[point_id].y, &mlx->textures.scene, color);
		ft_put_pixel((pos.x - 1) + point[point_id].x, \
						pos.y + point[point_id].y, &mlx->textures.scene, color);
		ft_put_pixel(pos.x + point[point_id].x, \
				(pos.y + 1) + point[point_id].y, &mlx->textures.scene, color);
		ft_put_pixel(pos.x + point[point_id].x, \
				(pos.y - 1) + point[point_id].y, &mlx->textures.scene, color);
		counter += 0.8;
	}
	return (point);
}

void	put_buffer_in_circle(t_i_pos pos, t_mlx_texture *image, t_int4 color)
{
	int		point;
	t_i_pos	d;

	if (pos.x < 0 || pos.y < 0)
		return ;
	d.x = abs(pos.x - 80);
	d.y = abs(pos.y - 80);
	if (d.x > 75 || d.x > 75)
		return ;
	point = pos.x * 4 + 4 * pos.y * image->len.x;
	image->buff[point + 2] = ft_int4_dcomp(color, 1);
	image->buff[point + 1] = ft_int4_dcomp(color, 2);
	image->buff[point] = ft_int4_dcomp(color, 3);
	return ;
}

void	text_to_buff_in_circle(t_i_pos pos, t_mlx_texture *src, t_mlx_texture *dst)
{
	int		begin_src_y;
	int		begin_dst_y;
	t_i_pos	counter;

	counter.y = 0;
	while (counter.y < (src->size_line / 4))
	{
		begin_dst_y = (pos.y + counter.y) * dst->size_line;
		begin_src_y = counter.y * src->size_line;
		counter.x = 0;
		while (counter.x < src->size_line)
		{
			dst->buff[begin_dst_y + pos.x * 4 + counter.x] = \
			src->buff[begin_src_y + counter.x];
			counter.x++;
		}
		counter.y++;
	}
}

void	draw_minimap(t_main *config)
{
	t_i_pos	pos;
	t_int4	color;
	t_i_pos	*point;

	pos.x = 80;
	pos.y = 80;
	color = ft_int4_comp(0, 255, 0, 0);
	point = draw_circle(pos, color, 75, &config->mlx);
	pos.x = 5;
	pos.y = 5;
	text_to_buff_in_circle(pos, &config->mlx.textures.north, &config->mlx.textures.scene);
	return ;
}
