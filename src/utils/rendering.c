/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:36:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 01:56:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_return_value	init_rendering(t_main *config)
{
	if (init_mlx(&config->mlx))
		return (1);
	if (load_textures(config))
		return (1);
	return (0);
}

t_return_value	start_rendering(t_main *config)
{
	if (init_rendering(config))
	{
		free_mlx(&config->mlx);
		return (1);
	}
	mlx_loop(config->mlx.ptr);
	free_mlx(&config->mlx);
	return (0);
}
