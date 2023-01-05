/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:55:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	close_file(int fd)
{
	if (fd > -1)
		close(fd);
}

void	free_entry_parsing(t_parse *parsing)
{
	close_file(parsing->map_fd);
	ft_free_char_pointer(parsing->north_file_path);
	ft_free_char_pointer(parsing->south_file_path);
	ft_free_char_pointer(parsing->west_file_path);
	ft_free_char_pointer(parsing->east_file_path);
	if (parsing->map)
		ft_free_char_pp(parsing->map);
	ft_get_next_line(-2);
}
