/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:01:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 06:38:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_minimap_player_square(t_mlx_textures *text, t_minimap mini)
{
	t_i_pos	pos;

	if (mini.zoomed)
	{
		pos.x = MINI_EXPANDED_CENTER_X - (int)(text->mini_player.len.x / 2);
		pos.y = MINI_EXPANDED_CENTER_Y - (int)(text->mini_player.len.y / 2);
	}
	else
	{
		pos.x = MINI_CENTER_X - (int)(text->mini_player.len.x / 2);
		pos.y = MINI_CENTER_Y - (int)(text->mini_player.len.y / 2);
	}
	text_to_buff_circle(pos, &text->mini_player, &text->scene, mini.circle);
}

void	draw_minimap_player_angle(t_mlx_textures *text, t_minimap mini, float angle)
{
	t_line	line;
	t_d_pos	delta;

	line.begin.x = mini.circle.center.x;
	line.begin.y = mini.circle.center.y;
	delta.x = cos(angle) * PLAYER_ANGLE_SIZE;
	delta.y = sin(angle) * PLAYER_ANGLE_SIZE;
	line.end.x = line.begin.x + delta.x;
	line.end.y = line.begin.y + delta.y;
	line.color = PLAYER_ANGLE_COLOR;
	put_line_in_circle(&text->scene, line, mini.circle);
}

void	draw_minimap_player(t_main *config)
{
	raycast_fov_entry(config, config->player.angle);
	draw_minimap_player_angle(&config->mlx.textures, config->mini, \
														config->player.angle);
	draw_minimap_player_square(&config->mlx.textures, config->mini);
}
