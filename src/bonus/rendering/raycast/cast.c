/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 03:05:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	choose_ray_text(t_ray *ray, t_d_pos ppos, t_mlx_textures *text)
{
	if (ray->save.x == ray->pos.x)
	{
		if (ray->hit == 2)
			ray->img_use = &text->mini_door_close;
		else if (ray->pos.x < ppos.x)
		{
			ray->img_use = &text->east;
			ray->t.x = ray->text_size - ray->t.x;
		}
		else
			ray->img_use = &text->west;
	}
	else
	{
		if (ray->hit == 2)
			ray->img_use = &text->mini_door_close;
		else if (ray->pos.y < ppos.y)
			ray->img_use = &text->south;
		else
		{
			ray->img_use = &text->north;
			ray->t.x = ray->text_size - ray->t.x;
		}
	}
}

void	choose_ray(t_main *config)
{
	double	dist;

	dist = get_dist(config->player.pos, config->ray.pos);
	if (config->ray.dist > dist)
	{
		config->ray.dist = dist;
		config->ray.save.x = config->ray.pos.x;
		config->ray.save.y = config->ray.pos.y;
		config->ray.t.x = (int)(config->ray.save.y) % config->ray.text_size;
	}
	else
		config->ray.t.x = (int)(config->ray.save.x) % config->ray.text_size;
	choose_ray_text(&config->ray, config->player.pos, &config->mlx.textures);
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
