/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:12:25 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fix_fisheyes(t_ray *ray, t_player player)
{
	float	cosinus_angle;

	cosinus_angle = player.angle - ray->angle;
	if (cosinus_angle < 0)
		cosinus_angle += PI2;
	if (cosinus_angle > PI2)
		cosinus_angle -= PI2;
	ray->dist *= cos(cosinus_angle);
}

void	set_texture_height(t_ray *ray, t_mlx_texture scene)
{
	ray->t_height = (CELL_SIZE * scene.len.x) / ray->dist;
	ray->ty_step = CELL_SIZE / (float)ray->t_height;
	ray->ty_offset = 0;
	if (ray->t_height > scene.len.y)
	{
		ray->ty_offset = (ray->t_height - scene.len.y) / 2;
		ray->t_height = scene.len.y;
	}
}

void	push_buff_scene_color(t_ray *ray, t_mlx_texture *scene, int counter)
{
	t_int4	rgb;
	t_int1	tmp_rgb[3];
	int		y;

	tmp_rgb[0] = ray->img_use->buff[(int)ray->t.x * 4 + \
											4 * (int)ray->t.y * CELL_SIZE + 2];
	tmp_rgb[1] = ray->img_use->buff[(int)ray->t.x * 4 + \
											4 * (int)ray->t.y * CELL_SIZE + 1];
	tmp_rgb[2] = ray->img_use->buff[(int)ray->t.x * 4 + \
											4 * (int)ray->t.y * CELL_SIZE];
	rgb = ft_int4_comp(tmp_rgb[0], tmp_rgb[1], tmp_rgb[2], 0);
	y = (int)(counter + scene->len.y / 2 - ray->t_height / 2);
	ft_put_pixel(ray->nbr, y, scene, rgb);
}

void	push_buff_pixel_text(t_ray *ray, t_mlx_texture *scene)
{
	int		counter;

	counter = 0;
	ray->t.y = ray->ty_offset * ray->ty_step;
	while (counter < ray->t_height)
	{
		if ((int)ray->t.x * 4 + 4 * (int)ray->t.y * CELL_SIZE >= 0)
			push_buff_scene_color(ray, scene, counter);
		ray->t.y += ray->ty_step;
		counter++;
	}
}

void	get_text(t_main *config)
{
	double	dist;
	t_f_pos	begin;
	t_f_pos	end;

	begin.x = config->parsing.map.size.x * CELL_SIZE;
	begin.y = config->parsing.map.size.y * CELL_SIZE;
	end.x = 0;
	end.y = 0;
	dist = get_dist(begin, end);
	if (config->ray.hit && config->ray.dist < dist)
	{
		fix_fisheyes(&config->ray, config->player);
		set_texture_height(&config->ray, config->mlx.textures.scene);
		push_buff_pixel_text(&config->ray, &config->mlx.textures.scene);
	}
}
