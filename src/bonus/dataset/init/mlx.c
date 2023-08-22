/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 02:25:44 by brda-sil         ###   ########.fr       */
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
	init_mlx_texture(&textures->mini_wall);
	init_mlx_texture(&textures->mini_void);
	init_mlx_texture(&textures->mini_player);
	init_mlx_texture(&textures->mini_door_close);
	init_mlx_texture(&textures->mini_door_open);
	init_mlx_texture(&textures->scene);
}

void	init_mlx_window(t_mlx *mlx, t_error *err)
{
	mlx->screen.x = SCREEN_SIZE_X;
	mlx->screen.y = SCREEN_SIZE_Y;
	mlx->win = FT_NULL;
	mlx->win_raycasting = FT_NULL;
	if (FULL_SCREEN)
		mlx_get_screen_size(mlx->ptr, &mlx->screen.x, &mlx->screen.y);
	debug_print(RENDER_SCREEN_SIZE, (void *)mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->screen.x, mlx->screen.y, \
															WINDOW_TITLE);
	if (!mlx->win)
		set_error_known_texture(err, ERRN_02, MAIN_WINDOW);
}

t_r_value	init_mlx(t_main *config)
{
	t_mlx	*mlx;

	mlx = &config->mlx;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (set_error(&config->err, 0, ERRN_01));
	mlx->frame_time = ((1000 / FPS) + 5);
	init_mlx_textures(&mlx->textures);
	init_mlx_window(mlx, &config->err);
	if (have_error(config->err, 4) & ERRN_02)
		return (1);
	init_mlx_hook(config);
	return (0);
}
