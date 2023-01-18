/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:05:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 11:07:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	check_permission(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	return (file);
}

void	close_file(int fd)
{
	if (fd > -1)
		close(fd);
}