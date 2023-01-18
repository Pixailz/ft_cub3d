/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:36:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	cast_ray_up(t_ray *ray, t_player player)
{
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)player.pos.y >> ray->bit_prec) << ray->bit_prec) - \
																		0.0001;
		ray->pos.x = (player.pos.y - ray->pos.y) * ray->a_tan + player.pos.x;
		ray->offset.y = -ray->text_size;
		ray->offset.x = -ray->offset.y * ray->a_tan;
	}
}

void	cast_ray_down(t_ray *ray, t_player player)
{
	if (ray->angle < PI)
	{
		ray->pos.y = (((int)player.pos.y >> ray->bit_prec) << ray->bit_prec) + \
																ray->text_size;
		ray->pos.x = (player.pos.y - ray->pos.y) * ray->a_tan + player.pos.x;
		ray->offset.y = ray->text_size;
		ray->offset.x = -ray->offset.y * ray->a_tan;
	}
}

void	cast_ray_horizontal(t_ray *ray, t_player player, t_map map)
{
	ray->depth_of_field = 0;
	cast_ray_up(ray, player);
	cast_ray_down(ray, player);
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->pos.x = player.pos.x;
		ray->pos.y = player.pos.y;
		ray->depth_of_field = map.size.y + MATRIX_OFFSET;
	}
	while (ray->depth_of_field < map.size.y + MATRIX_OFFSET)
	{
		ray->max.x = (int)(ray->pos.x) >> ray->bit_prec;
		ray->max.y = (int)(ray->pos.y) >> ray->bit_prec;
		if (!ray_hit(ray, map, map.size.y + MATRIX_OFFSET))
			increase_offset(ray);
	}
	ray->save.y = ray->pos.y;
	ray->save.x = ray->pos.x;
	ray->dist = get_dist(player.pos, ray->pos);
}
