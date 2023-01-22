/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/22 03:19:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	init_mlx_texture(t_mlx_texture *text)
{
	text->ptr = FT_NULL;
	text->buff = FT_NULL;
	text->bpp = -1;
	text->endian = -1;
	text->size_line = -1;
	text->len.x = -1;
	text->len.y = -1;
}

void	init_mlx_textures(t_mlx_textures *textures)
{
	init_mlx_texture(&textures->north);
	init_mlx_texture(&textures->south);
	init_mlx_texture(&textures->west);
	init_mlx_texture(&textures->east);
	init_mlx_texture(&textures->raycast_wall);
	init_mlx_texture(&textures->raycast_void);
	init_mlx_texture(&textures->raycast_player);
}

void	init_mlx_window(t_mlx *mlx, t_error *err)
{
	mlx->screen.x = SCREEN_SIZE_X;
	mlx->screen.y = SCREEN_SIZE_Y;
	if (FULL_SCREEN)
		mlx_get_screen_size(mlx->ptr, &mlx->screen.x, &mlx->screen.y);
	debug_print(RENDER_SCREEN_SIZE, (void *)mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->screen.x, mlx->screen.y, \
															WINDOW_TITLE);
	if (!mlx->win)
	{
		set_error_known_texture(err, ERRN_02, MAIN_WINDOW);
		return ;
	}
	if (RAYCAST_ENABLE)
	{
		mlx->win_raycasting = mlx_new_window(mlx->ptr, \
			RAYCAST_SCREEN_SIZE_X, RAYCAST_SCREEN_SIZE_Y, RAYCAST_TITLE);
		if (!mlx->win_raycasting)
		{
			set_error_known_texture(err, ERRN_02, RAYCAST_WINDOW);
			return ;
		}
	}
}

t_r_value	init_mlx(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (set_error(&config->err, 0, ERRN_01));
	init_mlx_textures(&mlx->textures);
	init_mlx_window(mlx, &config->err);
	init_mlx_hook(config);
	return (0);
}