/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 06:15:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

float	get_ratio(float nbr, t_ray ray)
{
	return ((nbr / ray.text_size) * ray.mini_cell_size);
}

void	ft_put_pixel(int x, int y, t_mlx_texture *image, t_int4 color)
{
	int	point;

	if (x < 0 || y < 0 || x > image->len.x || y > image->len.y)
		return ;
	point = x * 4 + 4 * y * image->len.x;
	image->buff[point + 2] = ft_int4_dcomp(color, 1);
	image->buff[point + 1] = ft_int4_dcomp(color, 2);
	image->buff[point] = ft_int4_dcomp(color, 3);
	return ;
}

t_bool	pos_is_not_in_circle(t_i_pos pos, int c_x, int c_y, t_circle circle)
{
	t_l_pos			pow;
	unsigned int	x_x;
	unsigned int	y_y;

	x_x = pos.x + c_x;
	y_y = pos.y + c_y;
	x_x -= circle.center.x;
	y_y -= circle.center.y;
	pow.x = (x_x) * (x_x);
	pow.y = (y_y) * (y_y);
	return (sqrt(pow.x + pow.y) < circle.radius + MINI_EDGE_TRESH);
}

void	ft_put_pixel_not_in_circle(t_i_pos pos, t_mlx_texture *image, t_int4 color, t_circle circle)
{
	int	point;

	if (pos.x < 0 || pos.y < 0 || pos.x > image->len.x || pos.y > image->len.y)
		return ;
	if (pos_is_not_in_circle(pos, 0, 0, circle))
		return ;
	point = pos.x * 4 + 4 * pos.y * image->len.x;
	image->buff[point + 2] = ft_int4_dcomp(color, 1);
	image->buff[point + 1] = ft_int4_dcomp(color, 2);
	image->buff[point] = ft_int4_dcomp(color, 3);
	return ;
}

int	check_in_img(t_ray ray, int point)
{
	if (point * (int)ray.t.y < 0)
		return (0);
	if (point * (int)ray.t.y + 2 >= point * ray.img_use->len.y)
		return (0);
	return (1);
}
