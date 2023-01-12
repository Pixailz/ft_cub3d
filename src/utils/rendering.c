/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:36:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 17:38:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_player_angle(char player_char)
{
	if (player_char == 'N')
		return (90);
	else if (player_char == 'S')
		return (270);
	else if (player_char == 'W')
		return (180);
	else
		return (0);
}

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
				config->player.angle = \
									get_player_angle(config->parsing.map[y][x]);
				config->player.pos.x = x + .5;
				config->player.pos.y = y + .5;
			}
			x++;
		}
		y++;
	}
	if (DEBUG)
		debug_print(RENDER_PLAYER, (void *)&config->player);
	draw_ray(config);
}

t_r_value	init_rendering(t_main *config)
{
	if (init_mlx(config))
		return (1);
	if (load_textures(config))
		return (1);
	get_player_pos(config);
	return (0);
}

t_r_value	start_rendering(t_main *config)
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
