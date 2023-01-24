/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:42 by brda-sil         ###   ########.fr       */
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

int	check_in_img(t_ray ray, int point)
{
	if (point * (int)ray.t.y < 0)
		return (0);
	if (point * (int)ray.t.y + 2 >= point * ray.img_use->len.y)
		return (0);
	return (1);
}
