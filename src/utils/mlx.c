/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 22:13:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_mlx_texture(t_mlx *mlx)
{
	mlx->north_text.ptr = FT_NULL;
	mlx->south_text.ptr = FT_NULL;
	mlx->west_text.ptr = FT_NULL;
	mlx->east_text.ptr = FT_NULL;
	mlx->mini_wall.ptr = FT_NULL;
	mlx->mini_void.ptr = FT_NULL;
	mlx->mini_player.ptr = FT_NULL;
}

t_return_value	init_mlx(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (set_error(0, ERRN_02));
	init_mlx_texture(mlx);
	mlx->screen_x = DEFAULT_SCREEN_3D_X;
	mlx->screen_y = DEFAULT_SCREEN_3D_Y;
	if (FULL_SCREEN)
		mlx_get_screen_size(mlx->ptr, &mlx->screen_x, &mlx->screen_y);
	debug_print(RENDER_SCREEN_SIZE, (void *)mlx);
	mlx->win_3d = mlx_new_window(mlx->ptr, mlx->screen_x, mlx->screen_y, \
															WINDOW_TITLE_3D);
	if (!mlx->win_3d)
		return (set_error(0, ERRN_03));
	mlx->win_ray = mlx_new_window(mlx->ptr, DEFAULT_SCREEN_RAYCAST_X, \
								DEFAULT_SCREEN_RAYCAST_Y, WINDOW_TITLE_RAYCAST);
	if (!mlx->win_ray)
		return (set_error(0, ERRN_04));
	init_mlx_hook_3d(config);
	init_mlx_hook_ray(config);
	return (0);
}

void	free_mlx_textures(t_mlx *mlx)
{
	if (mlx->north_text.ptr)
		mlx_destroy_image(mlx->ptr, mlx->north_text.ptr);
	if (mlx->south_text.ptr)
		mlx_destroy_image(mlx->ptr, mlx->south_text.ptr);
	if (mlx->west_text.ptr)
		mlx_destroy_image(mlx->ptr, mlx->west_text.ptr);
	if (mlx->east_text.ptr)
		mlx_destroy_image(mlx->ptr, mlx->east_text.ptr);
	if (mlx->mini_wall.ptr)
		mlx_destroy_image(mlx->ptr, mlx->mini_wall.ptr);
	if (mlx->mini_void.ptr)
		mlx_destroy_image(mlx->ptr, mlx->mini_void.ptr);
	if (mlx->mini_player.ptr)
		mlx_destroy_image(mlx->ptr, mlx->mini_player.ptr);
}

void	free_mlx(t_mlx *mlx)
{
	free_mlx_textures(mlx);
	mlx_destroy_window(mlx->ptr, mlx->win_3d);
	mlx_destroy_window(mlx->ptr, mlx->win_ray);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	mlx->ptr = FT_NULL;
	mlx = FT_NULL;
}
