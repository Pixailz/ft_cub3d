/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:12:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 22:14:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_map_point(t_main *config, char current_cell, int x, int y)
{
	if (current_cell == '1')
		mlx_put_image_to_window(config->mlx.ptr, \
							config->mlx.win_ray, config->mlx.mini_wall.ptr, \
							y * MINIMAP_CELL_SIZE, x * MINIMAP_CELL_SIZE);
	else if (current_cell == '0')
		mlx_put_image_to_window(config->mlx.ptr, \
							config->mlx.win_ray, config->mlx.mini_void.ptr, \
							y * MINIMAP_CELL_SIZE, x * MINIMAP_CELL_SIZE);
	else if (map_char_is_player(current_cell))
		mlx_put_image_to_window(config->mlx.ptr, \
							config->mlx.win_ray, config->mlx.mini_player.ptr, \
							y * MINIMAP_CELL_SIZE + (MINIMAP_CELL_SIZE / 2) - 4,
							x * MINIMAP_CELL_SIZE + (MINIMAP_CELL_SIZE / 2) - 4);
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

int	draw_ray(t_main *config)
{
	draw_ray_map(config);
	return (0);
}
