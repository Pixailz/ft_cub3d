/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:28:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 02:49:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_ray(int nbr_ray, t_ray *ray)
{
	if (ray->angle < 0)
		ray->angle += PI2;
	if (ray->angle > PI2)
		ray->angle -= PI2;
	ray->nbr = 0;
	ray->dist = 10000;
	ray->nbr_ray = nbr_ray;
	ray->hit = 0;
}
