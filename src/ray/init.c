/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 14:48:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_ray(float player_angle, t_ray *ray)
{
	ray->angle = player_angle;
	// if (ray->angle < 0)
	// 	ray->angle += PI2;
	// if (ray->angle > PI2)
	// 	ray->angle -= PI2;
	ray->a_tan = get_a_tan(player_angle);
	ray->n_tan = get_n_tan(player_angle);
	ray->nbr = 0;
	ray->dist = 100000;
}
