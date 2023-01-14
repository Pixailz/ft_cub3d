/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:38:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 18:48:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ray_hit(t_main *config)
{
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
							config->mlx.textures.mini_hit.ptr, \
							get_ratio(config->ray.save.x), \
							get_ratio(config->ray.save.y));
}

void	draw_fov(t_main *config)
{
	t_line	line;

	line.begin.x = get_ratio(config->player.pos.x);
	line.begin.y = get_ratio(config->player.pos.y);
	line.end.x = get_ratio(config->ray.save.x);
	line.end.y = get_ratio(config->ray.save.y);
	draw_line(config->mlx.ptr, config->mlx.win, line, 0x0000ff);
}
