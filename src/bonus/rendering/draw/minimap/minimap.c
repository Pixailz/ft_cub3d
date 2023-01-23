/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 15:25:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_mini_map_in_circle(t_main *config, char **map, t_d_pos ppos)
{
	char	current_char;
	t_i_pos	pos;
	t_ray	*ray;

	pos.x = MINI_CENTER_X;
	pos.y = MINI_CENTER_Y;
	ray = &config->ray;
	current_char = map[(int)ppos.y / ray->text_size][(int)ppos.x / ray->text_size];
	// printf("current_char %x {}\n", current_char);
	if (current_char == EMPTY_CHAR)
	{
		pos.x -= ray->mini_cell_size - (ppos.x / ray->text_size) * ray->mini_cell_size;
		pos.y -= ray->mini_cell_size - (ppos.y / ray->text_size) * ray->mini_cell_size;
		text_to_buff_circle(pos, &config->mlx.textures.mini_void, \
								&config->mlx.textures.scene);
	}	
	else if (current_char == WALL_CHAR)
	{
		text_to_buff_circle(pos, &config->mlx.textures.mini_wall, \
								&config->mlx.textures.scene);
	}
	// if (draw_mini_map_in_circle == EMPTY_CHAR)
	// {
	// 	pos.x -= config->mlx.textures.mini_void.len.x;
	// 	pos.y -= config->mlx.textures.mini_void.len.y;
	// 	text_to_buff_circle(pos, &config->mlx.textures.mini_void, &config->mlx.textures.scene);
	// }
}

void	draw_minimap(t_main *config)
{
	init_mini_map(&config->mlx.textures);
	draw_mini_map_in_circle(config, config->parse.map.matrix, \
															config->player.pos);
	return ;
}
