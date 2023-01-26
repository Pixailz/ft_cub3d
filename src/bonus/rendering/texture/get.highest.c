/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.highest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:36:45 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 12:08:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	get_texture_highest_size(t_i_pos *highest, t_mlx_a_text textures_a)
{
	int	counter;

	counter = 0;
	while (counter < textures_a.frame_nb)
	{
		get_highest_size(highest, textures_a.frame[counter]);
		counter++;
	}
}

t_i_pos	get_textures_highest_size(t_mlx_textures textures)
{
	t_i_pos	highest;

	highest.x = 0;
	highest.y = 0;
	get_texture_highest_size(&highest, textures.north);
	get_texture_highest_size(&highest, textures.south);
	get_texture_highest_size(&highest, textures.west);
	get_texture_highest_size(&highest, textures.east);
	return (highest);
}
