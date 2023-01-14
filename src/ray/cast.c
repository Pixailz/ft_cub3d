/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 18:56:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	choose_ray(t_main *config)
{
	float		dist;

	dist = get_dist(config->player, config->ray);
	if (config->ray.dist > dist)
	{
		config->ray.dist = dist;
		config->ray.save.x = config->ray.pos.x;
		config->ray.save.y = config->ray.pos.y;
		if (config->ray.pos.x < config->player.pos.x)
			config->ray.img_use = config->mlx.textures.north;
		else
			config->ray.img_use = config->mlx.textures.south;
		config->ray.t.x = (int)(config->ray.save.y) % CELL_SIZE;
	}
	else
	{
		if (config->ray.pos.y < config->player.pos.y)
			config->ray.img_use = config->mlx.textures.east;
		else
			config->ray.img_use = config->mlx.textures.west;
		config->ray.t.x = (int)(config->ray.save.x) % CELL_SIZE;
	}
}

void	cast_rays(float angle, t_main *config)
{
	init_ray(angle, &config->ray);
	cast_ray_horizontal(&config->ray, config->player, config->parsing.map);
	cast_ray_vertical(&config->ray, config->player, config->parsing.map);
	choose_ray(config);
}

void	cast_ray_entry(t_main *config)
{
	float	angle;
	float	to_add;
	int		first;

	first = 0;
	to_add = DR / (config->mlx.screen.x / FOV);
	angle = config->player.angle - (DR * (FOV / 2));
	while (TRUE)
	{
		if (angle > config->player.angle + DR * (FOV / 2))
			break ;
		cast_rays(angle, config);
		if (!first)
		{
			draw_fov(config);
			first++;
		}
		draw_ray_hit(config);
		angle += to_add;
	}
	draw_fov(config);
}
