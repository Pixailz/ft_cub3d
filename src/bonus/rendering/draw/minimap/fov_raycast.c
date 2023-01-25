/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:09:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 11:59:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	init_raycast_fov(t_ray *ray_fov, float angle, t_main *config)
{
	ray_fov->bit_prec = 4;
	ray_fov->text_size = 16;
	ray_fov->a_tan = -1 / tan(angle);
	ray_fov->n_tan = -tan(angle);
	ray_fov->hit = 0;
	ray_fov->angle = angle;
	if (ray_fov->angle < 0)
		ray_fov->angle += PI2;
	if (ray_fov->angle > PI2)
		ray_fov->angle -= PI2;
}

void	raycast_fov_cast(t_main *config, t_ray *ray_fov)
{
	double	dist;

	ray_fov->hit = 0;
	if (ray_fov->angle < 0)
		ray_fov->angle += PI2;
	if (ray_fov->angle > PI2)
		ray_fov->angle -= PI2;
	ray_fov->a_tan = get_a_tan(ray_fov->angle);
	ray_fov->n_tan = get_n_tan(ray_fov->angle);
	fov_cast_ray_horizontal(ray_fov, config->player, config->parse.map);
	fov_cast_ray_vertical(ray_fov, config->player, config->parse.map);
	dist = get_dist(config->player.pos, config->ray.pos);
	if (ray_fov->dist > dist)
	{
		ray_fov->dist = dist;
		ray_fov->save.x = ray_fov->pos.x;
		ray_fov->save.y = ray_fov->pos.y;
	}
}

void	raycast_fov_draw(t_main *config, t_ray ray_fov)
{
	t_line	line;

	line.begin.x = MINI_CENTER_X;
	line.begin.y = MINI_CENTER_Y;
	line.end.x = MINI_CENTER_X + ray_fov.save.x;
	line.end.y = MINI_CENTER_Y + ray_fov.save.y;
	line.color = 0x00ff00;
	put_line_in_circle(&config->mlx.textures.scene, line, config->mini.circle);
}

void	raycast_fov(t_main *config, float angle)
{
	t_ray	ray_fov;
	t_i_pos	end;
	float	to_add;

	to_add = DR / ((config->mini.circle.radius * 2) / FOV);
	ray_fov.text_size = 2;
	ray_fov.bit_prec = 1;
	ray_fov.angle = angle - (DR * (FOV / 2));
	ray_fov.nbr = 0;
	ray_fov.nbr_ray = 100;
	while (ray_fov.nbr < ray_fov.nbr_ray)
	{
		raycast_fov_cast(config, &ray_fov);
		raycast_fov_draw(config, ray_fov);
		ray_fov.angle += to_add;
		ray_fov.nbr++;
	}
	init_raycast_fov(&ray_fov, angle, config);
}
