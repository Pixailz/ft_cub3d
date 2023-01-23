/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:46:34 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 08:41:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	free_mlx_texture(void *mlx, t_mlx_texture *text)
{
	if (text->ptr)
		mlx_destroy_image(mlx, text->ptr);
}

void	free_mlx_textures(t_mlx *mlx)
{
	t_mlx_textures	*textures;

	textures = &mlx->textures;
	free_mlx_texture(mlx->ptr, &textures->north);
	free_mlx_texture(mlx->ptr, &textures->south);
	free_mlx_texture(mlx->ptr, &textures->west);
	free_mlx_texture(mlx->ptr, &textures->east);
	free_mlx_texture(mlx->ptr, &textures->mini_wall);
	free_mlx_texture(mlx->ptr, &textures->mini_void);
	free_mlx_texture(mlx->ptr, &textures->mini_player);
	free_mlx_texture(mlx->ptr, &textures->mini_door_close);
	free_mlx_texture(mlx->ptr, &textures->mini_door_open);
	free_mlx_texture(mlx->ptr, &textures->scene);
}

void	free_mlx(t_mlx *mlx, t_error err)
{
	free_mlx_textures(mlx);
	if (have_error(err, 5) ^ ERRN_01)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (RAY_ENABLE)
		if (have_error(err, 5) ^ ERRN_02)
			mlx_destroy_window(mlx->ptr, mlx->win_raycasting);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	mlx->ptr = FT_NULL;
	mlx = FT_NULL;
}
