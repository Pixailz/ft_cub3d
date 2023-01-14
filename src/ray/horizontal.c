/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 14:34:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cast_ray_up(t_ray *ray, t_player player)
{
	if (ray->angle > PI)
	{
		ray->pos.y = (((int)player.pos.y >> BIT_PREC) << BIT_PREC) - 0.0001;
		ray->pos.x = (player.pos.y - ray->pos.y) * ray->a_tan + player.pos.x;
		ray->offset.y = -CELL_SIZE;
		ray->offset.x = -ray->offset.y * ray->a_tan;
	}
}

void	cast_ray_down(t_ray *ray, t_player player)
{
	if (ray->angle < PI)
	{
		ray->pos.y = (((int)player.pos.y >> BIT_PREC) << BIT_PREC) + CELL_SIZE;
		ray->pos.x = (player.pos.y - ray->pos.y) * ray->a_tan + player.pos.x;
		ray->offset.y = CELL_SIZE;
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
		ray->depth_of_field = MAX_DOF;
	}
	while (ray->depth_of_field < MAX_DOF)
	{
		ray->max_x = (int)(ray->pos.x) >> BIT_PREC;
		ray->max_y = (int)(ray->pos.y) >> BIT_PREC;
		if (!ray_hit(ray, map))
			increase_offset(ray);
	}
	debug_print(RAY_HORIZONTAL, (void *)ray);
	ray->save.y = ray->pos.y;
	ray->save.x = ray->pos.x;
	ray->dist = get_dist(player, *ray);
}
