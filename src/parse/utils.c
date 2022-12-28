/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:03:31 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/27 09:06:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_permission(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	return (file);
}

char	*get_line(int file)
{
	char	*ptr;
	int		last_char_index;

	ptr = ft_get_next_line(file);
	if (!ptr)
		return (FT_NULL);
	last_char_index = ft_strlen(ptr) - 1;
	if (ptr[last_char_index] == '\n')
		ptr[last_char_index] = 0;
	debug_print(PARSE_LINE, (void *)ptr);
	return (ptr);
}
