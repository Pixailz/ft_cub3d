/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:46:00 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 20:46:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	draw_fov(t_main *config)
{
	t_line	line;

	if (RAYCAST_ENABLE)
	{
		line.begin.x = get_ratio(config->player.pos.x, config->ray);
		line.begin.y = get_ratio(config->player.pos.y, config->ray);
		line.end.x = get_ratio(config->ray.save.x, config->ray);
		line.end.y = get_ratio(config->ray.save.y, config->ray);
		draw_line(config->mlx.ptr, config->mlx.win_raycasting, line, 0xff0000);
	}
}
