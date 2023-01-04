/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:26:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 03:30:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	get_map(t_parse *main)
{
	char	*tmp_line;
	char	*tmp_joined;

	tmp_joined = (char *)ft_calloc(sizeof(char), 1);
	while (TRUE)
	{
		tmp_line = ft_get_next_line(main->file);
		if (!*tmp_line)
			break ;
		tmp_joined = ft_memjoin(tmp_joined, tmp_line);
		free(tmp_line);
	}
	if (tmp_line)
		free(tmp_line);
	if (!ft_strlen(tmp_joined))
	{
		free(tmp_joined);
		return (FALSE);
	}
	main->map = ft_cub3d_split(tmp_joined, '\n');
	free(tmp_joined);
	return (TRUE);
}

int	parse_map(t_parse *main)
{
	int	return_value;

	if (!get_map(main))
		return (12);
	debug_print(PARSE_GET_MAP_SPLITTED, (void *)main->map);
	return_value = check_map_content(main->map);
	return (return_value);
}
