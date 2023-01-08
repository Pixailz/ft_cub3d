/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 00:48:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (FULL_SCREEN)
		mlx_get_screen_size(mlx->ptr, &mlx->screen_x, &mlx->screen_y);
	else
	{
		mlx->screen_x = DEFAULT_SCREEN_X;
		mlx->screen_y = DEFAULT_SCREEN_Y;
	}
	debug_print(RENDER_SCREEN_SIZE, (void *)mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->screen_x, mlx->screen_y, \
		WINDOW_TITLE);
	init_mlx_hook(mlx);
	mlx_loop(mlx->ptr);
	free_mlx(mlx);
	return ;
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
}
