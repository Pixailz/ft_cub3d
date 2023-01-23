/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 02:25:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	ft_get_axis(int x, int y, t_main *config)
{
	if (x < SCREEN_SIZE_X * 0.45)
	{
		config->player.movement.rigth_angle = FALSE;
		config->player.movement.left_angle = TRUE;
		config->player.movement.r_speed = ((SCREEN_SIZE_X / 2 - x)) / (SCREEN_SIZE_X * 0.45);
	}
	else if (x > SCREEN_SIZE_X * 0.55)
	{
		config->player.movement.left_angle = FALSE;
		config->player.movement.rigth_angle = TRUE;
		config->player.movement.r_speed = (x - SCREEN_SIZE_X / 2) / (SCREEN_SIZE_X * 0.45);
	}
	else
	{
		config->player.movement.left_angle = FALSE;
		config->player.movement.rigth_angle = FALSE;
	}
	return (x + y);
}

int	ft_not_in_axis(t_main *config)
{
	config->player.movement.left_angle = FALSE;
	config->player.movement.rigth_angle = FALSE;
	return (0);
}
