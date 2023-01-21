/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 18:27:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	close_file(int fd)
{
	if (fd > -1)
		close(fd);
}

void	free_file(t_file *file)
{
	if (file->fd != -1)
		close_file(file->fd);
	if (file->path != FT_NULL)
	{
		free(file->path);
		file->path = FT_NULL;
	}
}
