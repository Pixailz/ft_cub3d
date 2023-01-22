/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:29:43 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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

void	get_player_pos(t_map map, t_player *player, int text_size)
{
	int		x;
	int		y;

	y = 0;
	while (map.matrix[y])
	{
		x = 0;
		while (map.matrix[y][x])
		{
			if (map_char_is_player(map.matrix[y][x]))
			{
				player->angle = get_player_angle(map.matrix[y][x]);
				player->pos.x = x * text_size + text_size / 2;
				player->pos.y = y * text_size + text_size / 2;
			}
			x++;
		}
		y++;
	}
	debug_print(RENDER_PLAYER, (void *)player);
}

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->angle = -1;
	player->delta.x = -1;
	player->delta.y = -1;
	player->movement.up = FALSE;
	player->movement.down = FALSE;
	player->movement.left = FALSE;
	player->movement.rigth = FALSE;
	player->movement.left_angle = FALSE;
	player->movement.rigth_angle = FALSE;
}
