/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:39 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 18:20:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_dist(t_player player, t_ray ray)
{
	float	diff_x;
	float	diff_y;
	float	dist;

	diff_x = ray.pos.x - player.pos.x;
	diff_y = ray.pos.y - player.pos.y;
	dist = sqrt(diff_x * diff_x + diff_y * diff_y);
	return (dist);
}

t_bool	ray_hit(t_ray *ray, t_map map, int to_add)
{
	if (ray->max.x >= 0 && ray->max.y >= 0)
	{
		if (ray->max.x < map.size.x && ray->max.y < map.size.y)
		{
			if (map.matrix[ray->max.y][ray->max.x] == WALL_CHAR)
			{
				ray->depth_of_field = to_add;
				ray->hit = 1;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

float	get_a_tan(float ray_angle)
{
	return (-1 / tan(ray_angle));
}

float	get_n_tan(float ray_angle)
{
	return (-tan(ray_angle));
}

void	increase_offset(t_ray *ray)
{
	ray->pos.x += ray->offset.x;
	ray->pos.y += ray->offset.y;
	ray->depth_of_field++;
}
