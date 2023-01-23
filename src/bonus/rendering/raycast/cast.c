/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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
		if (config->ray.hit == 2)
			config->ray.img_use = &config->mlx.textures.mini_door_close;
		config->ray.t.x = (int)(config->ray.save.y) % config->ray.text_size;
	}
	else
	{
		if (config->ray.pos.y < config->player.pos.y)
			config->ray.img_use = &config->mlx.textures.south;
		else
			config->ray.img_use = &config->mlx.textures.north;
		config->ray.t.x = (int)(config->ray.save.x) % config->ray.text_size;
	}
}

void	cast_rays(t_main *config)
{
	config->ray.hit = 0;
	if (config->ray.angle < 0)
		config->ray.angle += PI2;
	if (config->ray.angle > PI2)
		config->ray.angle -= PI2;
	config->ray.a_tan = get_a_tan(config->ray.angle);
	cast_ray_horizontal(&config->ray, config->player, config->parse.map);
	config->ray.n_tan = get_n_tan(config->ray.angle);
	cast_ray_vertical(&config->ray, config->player, config->parse.map);
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
	config->ray.nbr = 0;
	config->ray.nbr_ray = config->mlx.textures.scene.len.x;
	while (config->ray.nbr < config->ray.nbr_ray)
	{
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
