/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 15:09:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_file(t_file *file)
{
	file->fd = -1;
	file->path = FT_NULL;
}

void	free_file(t_file *file)
{
	if (file->fd != -1)
		close(file->fd);
	if (file->path != FT_NULL)
	{
		free(file->path);
		file->path = FT_NULL;
	}
}

void	set_file(t_file *file, char *path, int fd)
{
	file->fd = fd;
	file->path = path;
}
