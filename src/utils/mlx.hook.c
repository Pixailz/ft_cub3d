/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 01:50:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	end_hook(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}

int	key_press(int key_pressed, t_mlx *mlx)
{
	debug_print(RENDER_KEY_PRESS, (void *)&key_pressed);
	if (key_pressed == KEY_ESC)
		end_hook(mlx);
	return (0);
}

void	init_mlx_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 33, (1L << 17), end_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_press, mlx);
	mlx_do_key_autorepeaton(mlx->ptr);
	return ;
}
