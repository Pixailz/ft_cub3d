/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 02:03:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_mlx_texture(t_mlx *mlx)
{
	mlx->north_text.ptr = FT_NULL;
	mlx->south_text.ptr = FT_NULL;
	mlx->west_text.ptr = FT_NULL;
	mlx->east_text.ptr = FT_NULL;
}

t_return_value	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	init_mlx_texture(mlx);
	if (!mlx->ptr)
		return (set_error(0, ERRN_02));
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
	if (!mlx->win)
		return (set_error(0, ERRN_03));
	init_mlx_hook(mlx);
	return (0);
}

void	free_mlx_textures(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->north_text.ptr);
}

void	free_mlx(t_mlx *mlx)
{
	free_mlx_textures(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
}
