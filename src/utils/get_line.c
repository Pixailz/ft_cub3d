/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:28:08 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 20:12:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*parse_get_line(t_error *err, int file)
{
	char	*ptr;
	int		last_char_index;
	int		gnl_status;

	gnl_status = 0;
	ptr = ft_get_next_line(file, &gnl_status);
	if (gnl_status == 1)
	{
		set_error(err, 0, ERRN_01);
		return (FT_NULL);
	}
	last_char_index = ft_strlen(ptr) - 1;
	if (last_char_index == -1)
	{
		free(ptr);
		ptr = FT_NULL;
	}
	else if (ptr[last_char_index] == '\n')
		ptr[last_char_index] = 0;
	debug_print(PARSE_LINE, (void *)ptr);
	return (ptr);
}
