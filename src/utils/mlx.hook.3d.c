/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 21:37:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	end_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}

int	key_press_3d(int key_pressed, t_mlx *mlx)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_pressed);
	if (key_pressed == KEY_ESC)
		end_hook(mlx);
	return (0);
}

void	init_mlx_hook_3d(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx_hook(mlx->win_3d, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win_3d, 2, (1L << 0), key_press_3d, mlx);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
