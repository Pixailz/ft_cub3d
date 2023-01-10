/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:16 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 14:41:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	key_press_move_left(t_main *config)
{
	config->player.pos_x -= PLAYER_STEP;
	draw_ray(config);
}

void	key_press_move_right(t_main *config)
{
	config->player.pos_x += PLAYER_STEP;
	draw_ray(config);
}

void	key_press_move_up(t_main *config)
{
	return ;
}

void	key_press_move_down(t_main *config)
{
	return ;
}
