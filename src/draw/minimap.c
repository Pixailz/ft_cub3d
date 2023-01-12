/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:05:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_map_point(t_main *config, char current_cell, int x, int y)
{
	if (current_cell == '1')
		mlx_put_image_to_window(config->mlx.ptr, \
						config->mlx.win, config->mlx.textures.mini_wall.ptr, \
						y * MINIMAP_CELL_SIZE, x * MINIMAP_CELL_SIZE);
	else
		mlx_put_image_to_window(config->mlx.ptr, \
						config->mlx.win, config->mlx.textures.mini_void.ptr, \
						y * MINIMAP_CELL_SIZE, x * MINIMAP_CELL_SIZE);
}

void	draw_ray_map(t_main *config)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	map = config->parsing.map;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			draw_map_point(config, map[x][y], x, y);
			y++;
		}
		x++;
	}
}

void	draw_player_pos(t_main *config)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(config->player.pos.x * MINIMAP_CELL_SIZE - \
													MINIMAP_PLAYER_SIZE / 2);
	pos_y = (int)(config->player.pos.y * MINIMAP_CELL_SIZE - \
													MINIMAP_PLAYER_SIZE / 2);
	mlx_put_image_to_window(config->mlx.ptr, config->mlx.win, \
		config->mlx.textures.mini_player.ptr, pos_x, pos_y);
}

void	draw_player_angle(t_main *config)
{
	t_pos	begin;
	t_pos	end;

	begin.x = config->player.pos.x * MINIMAP_CELL_SIZE;
	begin.y = config->player.pos.y * MINIMAP_CELL_SIZE;
	end.x = config->player.pos.x * MINIMAP_CELL_SIZE;
	end.y = config->player.pos.y * MINIMAP_CELL_SIZE;
	if (config->player.angle == 0)
		end.x += PLAYER_ANGLE_SIZE;
	else if (config->player.angle == 180)
		end.x -= PLAYER_ANGLE_SIZE;
	else if (config->player.angle == 270)
		end.y += PLAYER_ANGLE_SIZE;
	else if (config->player.angle == 90)
		end.y -= PLAYER_ANGLE_SIZE;
	draw_line(config->mlx.ptr, config->mlx.win, get_line(begin, end), \
			PLAYER_ANGLE_COLOR);
}

int	draw_ray(t_main *config)
{
	draw_ray_map(config);
	draw_player_pos(config);
	draw_player_angle(config);
	return (0);
}