/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:44:51 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 04:05:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_ray_hit(t_main *config)
{
	if (RAY_ENABLE)
	{
		mlx_pixel_put(config->mlx.ptr, config->mlx.win_raycasting, \
			get_ratio(config->ray.save.x, config->ray), \
			get_ratio(config->ray.save.y, config->ray), \
			RAY_HIT_COLOR);
	}
}
