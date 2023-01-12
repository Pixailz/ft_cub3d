/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 21:44:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	end_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}

int	key_press(int key_pressed, t_main *config)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_pressed);
	if (key_pressed == KEY_ESC)
		end_hook(&config->mlx);
	else if (key_pressed == KEY_A)
		key_press_move_left(config);
	else if (key_pressed == KEY_D)
		key_press_move_right(config);
	else if (key_pressed == KEY_W)
		key_press_move_up(config);
	else if (key_pressed == KEY_S)
		key_press_move_down(config);
	else if (key_pressed == KEY_LEFT)
		key_press_move_angle_left(config);
	else if (key_pressed == KEY_RIGHT)
		key_press_move_angle_right(config);
	return (0);
}

void	init_mlx_hook(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx_hook(mlx->win, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press_3d, config);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
