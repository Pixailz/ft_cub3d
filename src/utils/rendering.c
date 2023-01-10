/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:36:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 02:03:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_player_pos(t_main *config)
{
	int	x;
	int	y;

	y = 0;
	while (config->parsing.map[y])
	{
		x = 0;
		while (config->parsing.map[y][x])
		{
			if (map_char_is_player(config->parsing.map[y][x]))
			{
				config->player.pos_x = x + .5;
				config->player.pos_y = y + .5;
			}
			x++;
		}
		y++;
	}
	dprintf(DEBUG_FD, "player pos (x:%f,y:%f)\n", \
									config->player.pos_x, config->player.pos_y);
}

t_return_value	init_rendering(t_main *config)
{
	if (init_mlx(config))
		return (1);
	if (load_textures(config))
		return (1);
	get_player_pos(config);
	return (0);
}

t_return_value	start_rendering(t_main *config)
{
	if (init_rendering(config))
	{
		free_mlx(&config->mlx);
		return (1);
	}
	draw_ray(config);
	mlx_loop(config->mlx.ptr);
	free_mlx(&config->mlx);
	return (0);
}
