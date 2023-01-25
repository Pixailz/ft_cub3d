/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:49:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 05:03:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	get_max_text_size(t_mlx_textures *textures, t_minimap *mini)
{
	mini->max_dir.x = textures->mini_wall.len.x;
	mini->max_dir.y = textures->mini_wall.len.y;
	mini->wall = &textures->mini_wall;
	get_highest_size(&mini->max_dir, textures->mini_void);
	mini->voidd = &textures->mini_void;
	get_highest_size(&mini->max_dir, textures->mini_player);
	mini->player = &textures->mini_player;
	get_highest_size(&mini->max_dir, textures->mini_door_close);
	mini->door_close = &textures->mini_door_close;
	get_highest_size(&mini->max_dir, textures->mini_door_open);
	mini->door_open = &textures->mini_door_open;
	if (mini->max_dir.x > mini->max_dir.y)
		mini->max_text_size = mini->max_dir.x;
	else
		mini->max_text_size = mini->max_dir.y;
}

void	init_mini_map(t_main *config)
{
	get_max_text_size(&config->mlx.textures, &config->mini);
	config->mini.img_2.x = config->mini.max_dir.x / 2;
	config->mini.img_2.y = config->mini.max_dir.y / 2;
	config->mini.max_dir.x = ((MINI_CIRCLE_RADIUS / config->mini.max_dir.x) \
																	+ 1);
	config->mini.max_dir.y = ((MINI_CIRCLE_RADIUS / config->mini.max_dir.y) \
																	+ 1);
}
