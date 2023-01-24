/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 03:08:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_mini_map_in_circle(t_main *config, char **map, t_i_pos pos)
{
	char			current_char;
	t_i_pos			pos_text;
	t_ray			*ray;

	ray = &config->ray;
	current_char = map[pos.y][pos.x];
	pos_text.x = pos.x * ray->mini_cell_size + MINI_CENTER_X;
	pos_text.y = pos.y * ray->mini_cell_size + MINI_CENTER_Y;
	if (current_char == EMPTY_CHAR)
		text_to_buff_circle(pos_text, &config->mlx.textures.mini_void, \
								&config->mlx.textures.scene);
	else if (current_char == WALL_CHAR)
		text_to_buff_circle(pos_text, &config->mlx.textures.mini_wall, \
								&config->mlx.textures.scene);
}

t_bool	protect_outof_map(int px, int py)
{
	t_i_pos	max;

	max.x = MINI_CENTER_X + MINI_CIRCLE_RADIUS;
	max.y = MINI_CENTER_Y + MINI_CIRCLE_RADIUS;
	if (px < 0 || px > max.x)
		return (FALSE);
	if (py < 0 || py > max.y)
		return (FALSE);
	return (TRUE);
}

void	draw_minimap(t_main *config)
{
	t_i_pos	pos;
	t_i_pos	ppos;
	t_i_pos	dir;
	char	**map;

	map = config->parse.map.matrix;
	init_mini_map(&config->mlx.textures);
	dir.x = MINI_CENTER_X;
	dir.y = MINI_CENTER_Y;
	text_to_buff_circle(dir, &config->mlx.textures.mini_void, \
								&config->mlx.textures.scene);
	/*
	// ppos.y = (int)(config->player.pos.y / config->ray.text_size);
	// ppos.x = (int)(config->player.pos.x / config->ray.text_size);
	// dir.x = -1 * config->ray.text_size;
	// dir.y = -1 * config->ray.text_size;
	// while (protect_outof_map(ppos.x + dir.x, ppos.y + dir.y) && dir.y <= 1)
	// {
	// 	pos.y = ppos.y + dir.y;
	// 	dir.x = -1;
	// 	while (protect_outof_map(ppos.x + dir.x, ppos.y + dir.y) && \
	// 		map[ppos.y + dir.y][ppos.x + dir.x] && dir.x <= 1)
	// 	{
	// 		pos.x = ppos.x + dir.x;
	// 		draw_mini_map_in_circle(config, config->parse.map.matrix, pos);
	// 		dir.x++;
	// 	}
	// 	dir.y++;
	// }
	// draw_mini_map_in_circle(config, config->parse.map.matrix, pos);
	return ;
	*/
}
