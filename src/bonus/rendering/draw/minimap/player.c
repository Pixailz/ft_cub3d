/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:01:47 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 02:30:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	draw_minimap_player(t_main *config, t_circle mini_circle)
{
	t_i_pos	pos;

	pos.x = MINI_CENTER_X - (int)(config->mlx.textures.mini_player.len.x / 2);
	pos.y = MINI_CENTER_Y - (int)(config->mlx.textures.mini_player.len.y / 2);
	text_to_buff_circle(pos, &config->mlx.textures.mini_player, \
							&config->mlx.textures.scene, mini_circle);
}
