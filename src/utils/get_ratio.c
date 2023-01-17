/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ratio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 03:27:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 19:54:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_ratio(float nbr, t_ray ray)
{
	return ((nbr / ray.text_size) * ray.raycast_cell_size);
}
