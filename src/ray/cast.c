/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 14:41:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cast_rays(float angle, t_main *config)
{
	t_pos	begin;
	t_pos	end;

	init_ray(angle, &config->ray);
	cast_ray_horizontal(&config->ray, config->player, config->parsing.map);
	cast_ray_vertical(&config->ray, config->player, config->parsing.map);
}

void	cast_ray_entry(t_main *config)
{
	cast_rays(config->player.angle, config);
	draw_ray_hit(config);
}
