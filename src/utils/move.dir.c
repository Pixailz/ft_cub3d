/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 15:17:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	key_press_move_left(t_main *config)
{
	config->player.pos.x -= PLAYER_STEP;
	draw_ray(config);
}

void	key_press_move_right(t_main *config)
{
	config->player.pos.x += PLAYER_STEP;
	draw_ray(config);
}

void	key_press_move_up(t_main *config)
{
	config->player.pos.y -= PLAYER_STEP;
	draw_ray(config);
}

void	key_press_move_down(t_main *config)
{
	config->player.pos.y += PLAYER_STEP;
	draw_ray(config);
}
