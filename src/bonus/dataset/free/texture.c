/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:46:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 09:46:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	free_file_list(t_file_l	*list)
{
	t_file_l	*next;

	next = list;
	while (next)
	{
		next = list->next;
		if (list->file.path)
			free(list->file.path);
		if (list->file.fd > -1)
			close(list->file.fd);
		free(list);
		list = next;
	}
}

void	free_textures(t_textures *textures)
{
	textures->ceiling = ft_int4_comp(0, 0, 0, 0);
	textures->floor = ft_int4_comp(0, 0, 0, 0);
	free_file_list(textures->north_file);
	free_file_list(textures->south_file);
	free_file_list(textures->west_file);
	free_file_list(textures->east_file);
}
