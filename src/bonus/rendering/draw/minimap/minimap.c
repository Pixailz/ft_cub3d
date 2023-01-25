/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 05:02:09 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 11:55:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	minimap_choose_text(t_main *config, t_minimap *mini)
{
	char	current_char;

	current_char = get_current_char_map(config->parse.map, mini->tmp_pos);
	if (current_char == WALL_CHAR)
		mini->img_to_use = &config->mlx.textures.mini_wall;
	else if (current_char == DOOR_CLOSE_CHAR)
		mini->img_to_use = &config->mlx.textures.mini_door_close;
	else if (current_char == DOOR_OPEN_CHAR)
		mini->img_to_use = &config->mlx.textures.mini_door_open;
	else
		mini->img_to_use = &config->mlx.textures.mini_void;
}

void	draw_mini_map_scaled(t_main *config, t_minimap *mini)
{
	t_i_pos			pos_text;
	t_i_pos			center;
	t_i_pos			scaled_dir;

	minimap_choose_text(config, mini);
	scaled_dir.x = mini->dir.x * mini->max_text_size;
	scaled_dir.y = mini->dir.y * mini->max_text_size;
	center.x = mini->circle.center.x + scaled_dir.x;
	center.y = mini->circle.center.y + scaled_dir.y;
	pos_text.x = center.x - mini->ppos_scaled.x;
	pos_text.y = center.y - mini->ppos_scaled.y;
	text_to_buff_circle(pos_text, mini->img_to_use, \
									&config->mlx.textures.scene, mini->circle);
}

void	draw_cross(t_main *config, t_circle circle)
{
	t_line	line;

	line.color = 0xff00;
	line.begin.x = circle.center.x - circle.radius;
	line.begin.y = circle.center.y;
	line.end.x = circle.center.x + circle.radius;
	line.end.y = circle.center.y;
	draw_line(config->mlx.ptr, config->mlx.win, line);
	line.begin.x = circle.center.x;
	line.begin.y = circle.center.y - circle.radius;
	line.end.x = circle.center.x;
	line.end.y = circle.center.y + circle.radius;
	draw_line(config->mlx.ptr, config->mlx.win, line);
}

t_i_pos	get_max_dir(t_minimap mini)
{
	if (mini.zoomed)
		return (mini.max_dir_zoomed);
	else
		return (mini.max_dir);
}

void	draw_minimap(t_main *config)
{
	t_minimap	*mini;
	t_i_pos		max_dir;

	mini = &config->mini;
	update_mini_map(config, mini);
	max_dir = get_max_dir(*mini);
	mini->dir.y = ~(max_dir.y - 1);
	while (mini->dir.y <= max_dir.y)
	{
		mini->dir.x = ~(max_dir.x - 1);
		while (mini->dir.x <= max_dir.x)
		{
			mini->tmp_pos.x = mini->id.x + mini->dir.x;
			mini->tmp_pos.y = mini->id.y + mini->dir.y;
			draw_mini_map_scaled(config, mini);
			mini->dir.x++;
		}
		mini->dir.y++;
	}
	draw_circle(mini->circle, &config->mlx.textures);
	draw_minimap_player(config);
	if (DEBUG && VERBOSE >= 2)
		draw_cross(config, mini->circle);
}
