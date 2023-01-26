/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.animated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:56:38 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 10:45:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	load_texture_animated(t_mlx_a_text *text, t_file_l *file, void *mlx_ptr)
{
	printf("list size %d\n", lstsize_file(file));
	return (0);
}

void	load_textures_animated(t_main *config)
{
	if (load_texture_animated(&config->mlx.textures.north, \
		config->parse.textures.north_file, config->mlx.ptr))
		set_error_known(&config->err, 1, ERRN_03, NORTH);

	// if (load_texture(&mlx->textures.south, textures->south_file->file.path, mlx->ptr))
	// 	set_error_known(&config->err, 1, ERRN_03, SOUTH);
	// if (load_texture(&mlx->textures.west, textures->west_file->file.path, mlx->ptr))
	// 	set_error_known(&config->err, 1, ERRN_03, WEST);
	// if (load_texture(&mlx->textures.east, textures->east_file->file.path, mlx->ptr))
	// 	set_error_known(&config->err, 1, ERRN_03, EAST);
}
