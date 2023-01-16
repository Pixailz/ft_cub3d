/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:36:59 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 01:53:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_player_angle(char player_char)
{
	if (player_char == 'N')
		return (PI3);
	else if (player_char == 'S')
		return (PI4);
	else if (player_char == 'W')
		return (PI);
	else
		return (0);
}

void	get_player_pos(t_main *config)
{
	char	**matrix;
	int		x;
	int		y;

	y = 0;
	matrix = config->parsing.map.matrix;
	while (config->parsing.map.matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (map_char_is_player(matrix[y][x]))
			{
				config->player.angle = get_player_angle(matrix[y][x]);
				config->player.pos.x = x * CELL_SIZE + CELL_SIZE / 2;
				config->player.pos.y = y * CELL_SIZE + CELL_SIZE / 2;
			}
			x++;
		}
		y++;
	}
	debug_print(RENDER_PLAYER, (void *)&config->player);
}

t_r_value	init_rendering(t_main *config)
{
	if (init_mlx(config))
		return (1);
	if (load_textures(config))
		return (1);
	get_player_pos(config);
	adjust_delta(&config->player);
	draw_base(config);
	draw_scene(config);
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
