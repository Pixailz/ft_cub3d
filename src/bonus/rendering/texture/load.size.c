/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:15:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 18:52:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	get_highest_size(t_i_pos *highest, t_mlx_texture text)
{
	if (highest->x < text.len.x)
		highest->x = text.len.x;
	if (highest->y < text.len.y)
		highest->y = text.len.y;
}

unsigned char	get_bit_prec(int highest)
{
	unsigned char	counter;

	if (highest <= 0)
		return (0);
	counter = 0;
	while (highest - (1 << counter) > 0)
		counter++;
	return (counter);
}

void	get_mini_size(t_main *config)
{
	t_i_pos			highest;
	t_mlx_textures	textures;

	textures = config->mlx.textures;
	highest.x = textures.mini_wall.len.x;
	highest.y = textures.mini_wall.len.y;
	if (highest.x < textures.mini_void.len.x)
		highest.x = textures.mini_void.len.x;
	if (highest.y < textures.mini_void.len.y)
		highest.y = textures.mini_void.len.y;
	if (highest.x > highest.y)
		config->ray.mini_cell_size = highest.x;
	else
		config->ray.mini_cell_size = highest.y;
	if (textures.mini_player.len.x > textures.mini_player.len.y)
		config->ray.mini_player_size = textures.mini_player.len.x;
	else
		config->ray.mini_player_size = textures.mini_player.len.y;
}

void	get_textures_size(t_main *config)
{
	t_mlx_textures	textures;
	t_i_pos			highest;

	textures = config->mlx.textures;
	highest.x = textures.north.len.x;
	highest.y = textures.north.len.y;
	get_highest_size(&highest, textures.south);
	get_highest_size(&highest, textures.west);
	get_highest_size(&highest, textures.east);
	get_mini_size(config);
	if (highest.x < highest.y)
		config->ray.text_size = highest.y;
	else
		config->ray.text_size = highest.x;
	config->ray.bit_prec = get_bit_prec(config->ray.text_size);
}
