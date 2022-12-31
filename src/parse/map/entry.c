/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:26:12 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/29 15:34:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**get_map(int file)
{
	char	*tmp_line;
	char	*tmp_joined;
	char	**tmp_splitted;

	tmp_joined = (char *)ft_calloc(sizeof(char), 1);
	while (TRUE)
	{
		tmp_line = ft_get_next_line(file);
		if (!*tmp_line)
			break ;
		tmp_joined = ft_memjoin(tmp_joined, tmp_line);
		free(tmp_line);
	}
	free(tmp_line);
	tmp_splitted = ft_cub3d_split(tmp_joined, '\n');
	free(tmp_joined);
	return (tmp_splitted);
}

int	parse_map_content(t_parse *main)
{
	return (0);
}

int	parse_map(t_parse *main)
{
	int	return_value;

	main->map = get_map(main->file);
	debug_print(PARSE_GET_MAP_SPLITTED, (void *)main->map);
	return_value = parse_map_content(main);
	return (-1);
}
