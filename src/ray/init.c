/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 18:35:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_ray(float player_angle, t_ray *ray)
{
	ray->angle = player_angle;
	ray->a_tan = get_a_tan(ray->angle);
	ray->n_tan = get_n_tan(ray->angle);
	if (ray->angle < 0)
		ray->angle += PI2;
	if (ray->angle > PI2)
		ray->angle -= PI2;
	ray->nbr = 0;
	ray->dist = 0;
	ray->hit = 0;
}
