/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:12:25 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/28 06:43:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	fix_fisheyes(t_ray *ray, t_player player)
{
	float	cosinus_angle;

	ray->dist_real = ray->dist;
	cosinus_angle = player.angle.x - ray->angle;
	if (cosinus_angle < 0)
		cosinus_angle += PI2;
	if (cosinus_angle > PI2)
		cosinus_angle -= PI2;
	ray->dist *= cos(cosinus_angle);
}

void	set_texture_height(t_ray *ray, t_mlx_texture scene, t_player player)
{
	(void)player;
	ray->t_height = (ray->text_size * scene.len.x) / ray->dist;
	ray->ty_step = (ray->img_use->len.y / (float)ray->t_height);
	ray->ty_offset = 0;
	if (ray->t_height > scene.len.y )
	{
		ray->ty_offset = (ray->t_height - scene.len.y) * player.angle.y;
		ray->t_height = scene.len.y;
	}
}

t_int4	push_buff_scene_get_color(t_ray ray, int point)
{
	double	ratio_fog;
	t_int1	tmp_rgb[3];
	t_int4	rgb;

	if (ray.dist_real > FOG * ray.text_size)
		return (0);
	tmp_rgb[2] = ray.img_use->buff[point + 2];
	tmp_rgb[1] = ray.img_use->buff[point + 1];
	tmp_rgb[0] = ray.img_use->buff[point];
	if (ray.dist_real > FOG * ray.text_size * RATIO_FOG && \
										ray.dist_real < FOG * ray.text_size)
	{
		ratio_fog = 1 - (ray.dist_real - (FOG * ray.text_size * RATIO_FOG)) / \
					((FOG * ray.text_size) * (1 - RATIO_FOG));
		tmp_rgb[2] *= ratio_fog;
		tmp_rgb[1] *= ratio_fog;
		tmp_rgb[0] *= ratio_fog;
	}
	rgb = ft_int4_comp(tmp_rgb[0], tmp_rgb[1], tmp_rgb[2], 0);
	return (rgb);
}

t_int4	push_buff_scene_get_color(t_ray ray, int point)
{
	double	ratio_fog;
	t_int1	tmp_rgb[3];
	t_int4	rgb;

	if (ray.dist_real > FOG * ray.text_size || !ray.hit)
		return (0);
	tmp_rgb[2] = ray.img_use->buff[point + 2];
	tmp_rgb[1] = ray.img_use->buff[point + 1];
	tmp_rgb[0] = ray.img_use->buff[point];
	if (ray.dist_real > FOG * ray.text_size * RATIO_FOG && \
										ray.dist_real < FOG * ray.text_size)
	{
		ratio_fog = 1 - (ray.dist_real - (FOG * ray.text_size * RATIO_FOG)) / \
					((FOG * ray.text_size) * (1 - RATIO_FOG));
		tmp_rgb[2] *= ratio_fog;
		tmp_rgb[1] *= ratio_fog;
		tmp_rgb[0] *= ratio_fog;
	}
	rgb = ft_int4_comp(tmp_rgb[0], tmp_rgb[1], tmp_rgb[2], 0);
	return (rgb);
}

void	push_buff_scene_color(t_ray *ray, t_mlx_texture *scene, int counter, t_player player)
{
	t_int4	rgb;
	int		y;
	int		point;

	point = (int)(ray->t.x * ray->img_use->len.x / ray->text_size) * 4 + \
			(int)ray->t.y * ray->img_use->len.x * 4;
	if (point + 2 <= ray->img_use->size_line * ray->img_use->len.y)
	{
		rgb = push_buff_scene_get_color(*ray, point);
		y = (int)(counter + scene->len.y /2 - ray->t_height  *player.angle.y );
		ft_put_pixel(ray->nbr, y + ((player.angle.y - 0.5) * scene->len.y), scene, rgb);
	}
}

void	push_buff_pixel_text(t_ray *ray, t_mlx_texture *scene, t_player player)
{
	int	counter;

	counter = 0;
	ray->t.y = ray->ty_offset * ray->ty_step;
	while (counter < ray->t_height && counter + (player.angle_y - 0.5) * scene->len.y < scene->len.y)
	{
		push_buff_scene_color(ray, scene, counter, player);
		ray->t.y += ray->ty_step;
		counter++;
	}
}

void	get_text(t_main *config)
{
	double	dist;
	t_d_pos	begin;
	t_d_pos	end;

	fix_fisheyes(&config->ray, config->player);
	begin.x = 0;
	begin.y = FOG * config->ray.text_size;
	end.x = 0;
	end.y = 0;
	dist = get_dist(begin, end);
	if (config->ray.dist < dist)
	{
		set_texture_height(&config->ray, config->mlx.textures.scene, config->player);
		push_buff_pixel_text(&config->ray, &config->mlx.textures.scene, config->player);
	}
	else
	{
		printf("x : %d\n",config->ray.nbr);
		config->ray.hit = 0;
		config->ray.dist = dist;
		set_texture_height(&config->ray, config->mlx.textures.scene, config->player);
		push_buff_pixel_text(&config->ray, &config->mlx.textures.scene, config->player);
	}
}
