/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:38:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 14:49:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ray_hit(t_main *config)
{
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
							config->mlx.textures.mini_hit.ptr, \
							get_ratio(config->ray.pos.x), \
							get_ratio(config->ray.pos.y));
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
							config->mlx.textures.mini_hit.ptr, \
							get_ratio(config->ray.save.x), \
							get_ratio(config->ray.save.y));
}
