/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:22:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 00:59:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	hit_wall(t_player player, t_map map, int text_size)
{
	int	pos_x_text_size;
	int	pos_y_text_size;

	pos_x_text_size = player.pos.x / text_size;
	pos_y_text_size = player.pos.y / text_size;
	if (!COLLISION)
		return (FALSE);
	if (pos_x_text_size >= 0 && pos_y_text_size >= 0)
	{
		if (pos_x_text_size < map.size.x + 1 && pos_y_text_size < map.size.y + 1)
		{
			if (map.matrix[pos_y_text_size][pos_x_text_size] == WALL_CHAR)
				return (TRUE);
			if (map.matrix[pos_y_text_size][pos_x_text_size] == DOOR_CLOSE_CHAR)
				return (TRUE);
		}
	}
	return (FALSE);
}

t_d_pos	move_get_dir(t_player player)
{
	t_d_pos	dir;

	dir.x = player.delta.x;
	dir.y = player.delta.y;
	if (player.movement.shifting)
	{
		dir.x *= SHIFTING_SPEED;
		dir.y *= SHIFTING_SPEED;
	}
	return (dir);
}

void	move_dir_forward(t_player *player, int text_size, t_map map)
{
	t_d_pos	dir;

	dir = move_get_dir(*player);
	player->pos.x += dir.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x -= dir.x;
	player->pos.y += dir.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y -= dir.y;
}

void	move_dir_backward(t_player *player, int text_size, t_map map)
{
	t_d_pos	dir;

	dir = move_get_dir(*player);
	player->pos.x -= dir.x;
	if (hit_wall(*player, map, text_size))
		player->pos.x += dir.x;
	player->pos.y -= dir.y;
	if (hit_wall(*player, map, text_size))
		player->pos.y += dir.y;
}
