/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 00:52:16 by brda-sil         ###   ########.fr       */
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
		free_file(&list->file);
		free(list);
		list = next;
	}
}

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
