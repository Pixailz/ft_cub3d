/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:30:50 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 05:05:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

t_r_value	init_rendering(t_main *config)
{
	if (init_mlx(config))
		return (1);
	if (load_textures(config))
		return (1);
	get_player_pos(config->parse.map, &config->player, config->ray.text_size);
	adjust_delta(&config->player, config->ray.text_size);
	return (0);
}

t_r_value	start_rendering(t_main *config)
{
	if (init_rendering(config))
	{
		free_mlx(&config->mlx, config->err);
		return (1);
	}
	mlx_loop_hook(config->mlx.ptr, draw_frame, config);
	mlx_loop(config->mlx.ptr);
	free_mlx(&config->mlx, config->err);
	return (0);
}
