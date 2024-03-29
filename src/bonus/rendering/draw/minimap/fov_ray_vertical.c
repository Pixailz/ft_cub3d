/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_ray_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:09:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 07:44:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	fov_cast_ray_right(t_ray *ray, t_player player)
{
	if (ray->angle > PI4 && ray->angle < PI3)
	{
		ray->pos.x = (((int)player.pos.x >> ray->bit_prec) << ray->bit_prec) - \
																		0.0001;
		ray->pos.y = (player.pos.x - ray->pos.x) * ray->n_tan + player.pos.y;
		ray->offset.x = -ray->text_size;
		ray->offset.y = -ray->offset.x * ray->n_tan;
	}
}

void	fov_cast_ray_left(t_ray *ray, t_player player)
{
	if (ray->angle < PI4 || ray->angle > PI3)
	{
		ray->pos.x = (((int)player.pos.x >> ray->bit_prec) << ray->bit_prec) + \
																ray->text_size;
		ray->pos.y = (player.pos.x - ray->pos.x) * ray->n_tan + player.pos.y;
		ray->offset.x = ray->text_size;
		ray->offset.y = -ray->offset.x * ray->n_tan;
	}
}

void	fov_cast_ray_vertical(t_ray *ray, t_player player, t_map map)
{
	ray->depth_of_field = 0;
	fov_cast_ray_right(ray, player);
	fov_cast_ray_left(ray, player);
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->pos.x = player.pos.x;
		ray->pos.y = player.pos.y;
		ray->depth_of_field = map.size.x;
	}
	while (ray->depth_of_field < map.size.x)
	{
		ray->max.x = (unsigned long int)(ray->pos.x) >> ray->bit_prec;
		ray->max.y = (unsigned long int)(ray->pos.y) >> ray->bit_prec;
		if (!ray_hit(ray, map, map.size.x))
			increase_offset(ray);
	}
	debug_print(RAY_VERTICAL, (void *)ray);
}
