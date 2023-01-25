/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:33:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 08:47:16 by brda-sil         ###   ########.fr       */
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
