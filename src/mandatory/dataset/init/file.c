/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/21 03:10:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	init_file(t_file *file)
{
	file->fd = -1;
	file->path = FT_NULL;
	file->err_no = 0;
}

void	set_file(t_file *file, char *path, int fd)
{
	file->fd = fd;
	file->path = path;
	file->err_no = errno;
}
