/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 18:10:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	choose_ray(t_main *config)
{
	float		dist;

	dist = get_dist(config->player.pos, config->ray.pos);
	if (config->ray.dist > dist)
	{
		config->ray.dist = dist;
		config->ray.save.x = config->ray.pos.x;
		config->ray.save.y = config->ray.pos.y;
		if (config->ray.pos.x < config->player.pos.x)
			config->ray.img_use = &config->mlx.textures.east;
		else
			config->ray.img_use = &config->mlx.textures.west;
		config->ray.t.x = (int)(config->ray.save.y) % CELL_SIZE;
	}
	else
	{
		if (config->ray.pos.y < config->player.pos.y)
			config->ray.img_use = &config->mlx.textures.south;
		else
			config->ray.img_use = &config->mlx.textures.north;
		config->ray.t.x = (int)(config->ray.save.x) % CELL_SIZE;
	}
}

void	cast_rays(t_main *config)
{
	config->ray.hit = 0;
	config->ray.a_tan = get_a_tan(config->ray.angle);
	cast_ray_horizontal(&config->ray, config->player, config->parsing.map);
	config->ray.n_tan = get_n_tan(config->ray.angle);
	cast_ray_vertical(&config->ray, config->player, config->parsing.map);
	choose_ray(config);
	get_text(config);
}

void	cast_ray_entry(t_main *config)
{
	float	to_add;
	int		first;

	first = 0;
	to_add = DR / (config->mlx.screen.x / FOV);
	config->ray.angle = config->player.angle - (DR * (FOV / 2));
	init_ray(config->mlx.textures.scene.len.x, &config->ray);
	while (config->ray.nbr < config->ray.nbr_ray)
	{
		if (config->ray.angle > config->player.angle + DR * (FOV / 2))
			break ;
		cast_rays(config);
		if (!first)
		{
			draw_fov(config);
			first++;
		}
		draw_ray_hit(config);
		config->ray.angle += to_add;
		config->ray.nbr++;
	}
	draw_fov(config);
}
