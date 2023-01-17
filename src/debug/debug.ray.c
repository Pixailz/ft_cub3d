/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:15:15 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 18:59:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	debug_print_ray_info(char *title, t_ray ray)
{
	dprintf(DEBUG_FD, "%s: (x:%.2f,y:%.2f)\n", \
		title, ray.pos.x / ray.text_size, ray.pos.y / ray.text_size);
}

void	debug_print_ray(int mode, void *ptr)
{
	if (VERBOSE >= 3)
	{
		if (mode == RAY_HORIZONTAL)
			debug_print_ray_info("Horizontal", *(t_ray *)ptr);
		else if (mode == RAY_VERTICAL)
			debug_print_ray_info("Vertical", *(t_ray *)ptr);
	}
}
