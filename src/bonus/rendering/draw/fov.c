/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:46:00 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 01:12:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_fov(t_main *config)
{
	t_line	line;

	if (RAY_ENABLE)
	{
		line.begin.x = get_ratio(config->player.pos.x, config->ray);
		line.begin.y = get_ratio(config->player.pos.y, config->ray);
		line.end.x = get_ratio(config->ray.save.x, config->ray);
		line.end.y = get_ratio(config->ray.save.y, config->ray);
		line.color = 0xff0000;
		draw_line(config->mlx.ptr, config->mlx.win_raycasting, line);
	}
}
