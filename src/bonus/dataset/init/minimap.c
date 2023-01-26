/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:49:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 06:51:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	get_max_text_size(t_mlx_textures *text, t_minimap *mini, t_i_pos *max)
{
	max->x = text->mini_wall.len.x;
	max->y = text->mini_wall.len.y;
	mini->wall = &text->mini_wall;
	get_highest_size(max, text->mini_void);
	mini->voidd = &text->mini_void;
	get_highest_size(max, text->mini_player);
	mini->player = &text->mini_player;
	get_highest_size(max, text->mini_door_close);
	mini->door_close = &text->mini_door_close;
	get_highest_size(max, text->mini_door_open);
	mini->door_open = &text->mini_door_open;
}

void	init_mini_map(t_main *config)
{
	config->mini.zoomed = FALSE;
	get_max_text_size(&config->mlx.textures, &config->mini, \
													&config->mini.max_dir);
	if (config->mini.max_dir.x > config->mini.max_dir.y)
		config->mini.max_text_size = config->mini.max_dir.x;
	else
		config->mini.max_text_size = config->mini.max_dir.y;
	config->mini.max_dir.x = ((MINI_CIRCLE_RADIUS / \
											config->mini.max_dir.x) + 1);
	config->mini.max_dir.y = ((MINI_CIRCLE_RADIUS / \
											config->mini.max_dir.y) + 1);
	config->mini.img_2.x = config->mini.max_dir.x / 2;
	config->mini.img_2.y = config->mini.max_dir.y / 2;
	get_max_text_size(&config->mlx.textures, &config->mini, \
											&config->mini.max_dir_zoomed);
	config->mini.max_dir_zoomed.x = ((MINI_EXPANDED_CIRCLE_RADIUS / \
											config->mini.max_dir.x) + 1);
	config->mini.max_dir_zoomed.y = ((MINI_EXPANDED_CIRCLE_RADIUS / \
											config->mini.max_dir.y) + 1);
}
