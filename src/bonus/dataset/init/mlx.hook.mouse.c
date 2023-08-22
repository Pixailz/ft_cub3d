/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 13:14:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	ft_get_axis(int x, int y, t_main *config)
{
	config->player.movement.left_angle = FALSE;
	config->player.movement.right_angle = FALSE;
	config->player.movement.up_angle = FALSE;
	config->player.movement.down_angle = FALSE;
	config->player.movement.r_speed_y = 1;
	if (x < config->mlx.screen.x * 0.45)
	{
		config->player.movement.left_angle = TRUE;
		config->player.movement.r_speed = ((config->mlx.screen.x / 2 - x)) / \
								(config->mlx.screen.x * 0.45 / TURN_SENSIVITY);
	}
	else if (x > config->mlx.screen.x * 0.55)
	{
		config->player.movement.right_angle = TRUE;
		config->player.movement.r_speed = (x - config->mlx.screen.x / 2) / \
								(config->mlx.screen.x * 0.45 / TURN_SENSIVITY);
	}
	if (y < config->mlx.screen.y * 0.45)
	{
		config->player.movement.up_angle = TRUE;
		config->player.movement.r_speed_y = ((config->mlx.screen.y / 2 - y)) / \
								(config->mlx.screen.y * 0.45 / TURN_SENSIVITY);
	}
	else if (y > config->mlx.screen.y * 0.55)
	{
		config->player.movement.down_angle = TRUE;
		config->player.movement.r_speed_y = (y - config->mlx.screen.y / 2) / \
								(config->mlx.screen.y * 0.45 / TURN_SENSIVITY);
	}
	return (y);
}

int	ft_not_in_axis(t_main *config)
{
	config->player.movement.left_angle = FALSE;
	config->player.movement.right_angle = FALSE;
	config->player.movement.up_angle = FALSE;
	config->player.movement.down_angle = FALSE;
	return (0);
}
