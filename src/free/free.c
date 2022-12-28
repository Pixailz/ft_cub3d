/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:50:13 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/28 07:44:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	close_file(int fd)
{
	if (fd > -1)
		close(fd);
}

void	free_close_file(t_parse *main)
{
	close_file(main->file);
	close_file(main->north_file);
	close_file(main->south_file);
	close_file(main->west_file);
	close_file(main->east_file);
}

void	free_entry(t_parse *main)
{
	free_close_file(main);
	if (main->map)
		ft_free_char_pp(main->map);
	ft_get_next_line(-2);
}
