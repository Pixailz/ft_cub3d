/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 14:47:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cast_ray_rigth(t_ray *ray, t_player player)
{
	if (ray->angle > PI2 || ray->angle < PI3)
	{
		ray->pos.x = (((int)player.pos.x >> BIT_PREC) << BIT_PREC) - 0.0001;
		ray->pos.y = (player.pos.x - ray->pos.x) * ray->n_tan + player.pos.y;
		ray->offset.x = -CELL_SIZE;
		ray->offset.y = -ray->offset.x * ray->n_tan;
	}
}

void	cast_ray_left(t_ray *ray, t_player player)
{
	if (ray->angle < PI2 && ray->angle > PI3)
	{
		ray->pos.x = (((int)player.pos.x >> BIT_PREC) << BIT_PREC) + CELL_SIZE;
		ray->pos.y = (player.pos.x - ray->pos.x) * ray->n_tan + player.pos.y;
		ray->offset.x = CELL_SIZE;
		ray->offset.y = -ray->offset.x * ray->n_tan;
	}
}

void	cast_ray_vertical(t_ray *ray, t_player player, t_map map)
{
	ray->depth_of_field = 0;
	ray->hit = 0;
	cast_ray_rigth(ray, player);
	cast_ray_left(ray, player);
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
	debug_print(RAY_VERTICAL, (void *)ray);
}
