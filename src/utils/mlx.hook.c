/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/16 17:53:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	end_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}

t_bool	is_movement_key(int key_code)
{
	if (key_code == KEY_A || key_code == KEY_D || key_code == KEY_W || \
		key_code == KEY_S || key_code == KEY_LEFT || key_code == KEY_RIGHT)
		return (TRUE);
	return (FALSE);
}

void	move(int key_code, t_main *config)
{
	if (key_code == KEY_A)
		key_press_move_left(&config->player);
	else if (key_code == KEY_D)
		key_press_move_right(&config->player);
	else if (key_code == KEY_W)
		key_press_move_up(&config->player);
	else if (key_code == KEY_S)
		key_press_move_down(&config->player);
	else if (key_code == KEY_LEFT)
		key_press_move_angle_left(&config->player);
	else if (key_code == KEY_RIGHT)
		key_press_move_angle_right(&config->player);
	draw_scene(config);
}

int	key_press(int key_code, t_main *config)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_code);
	if (is_movement_key(key_code))
		move(key_code, config);
	else if (key_code == KEY_ESC)
		return (end_hook(&config->mlx));
	return (0);
}

void	init_mlx_hook(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx_hook(mlx->win, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, config);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
