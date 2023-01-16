/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:38:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 18:11:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ray_hit(t_main *config)
{
	if (RAYCAST_ENABLE)
	{
		mlx_put_image_to_window(config->mlx.ptr, config->mlx.win_raycasting, \
								config->mlx.textures.mini_hit.ptr, \
								get_ratio(config->ray.save.x), \
								get_ratio(config->ray.save.y));
	}
}

void	draw_fov(t_main *config)
{
	t_line	line;

	if (RAYCAST_ENABLE)
	{
		line.begin.x = get_ratio(config->player.pos.x);
		line.begin.y = get_ratio(config->player.pos.y);
		line.end.x = get_ratio(config->ray.save.x);
		line.end.y = get_ratio(config->ray.save.y);
		draw_line(config->mlx.ptr, config->mlx.win_raycasting, line, 0xff0000);
	}
}
