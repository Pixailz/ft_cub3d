/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:26:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:14:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	get_map(t_parse *parsing)
{
	char	*tmp_line;
	char	*tmp_joined;

	tmp_joined = (char *)ft_calloc(sizeof(char), 1);
	while (TRUE)
	{
		tmp_line = ft_get_next_line(parsing->map_fd);
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
	parsing->map = ft_cub3d_split(tmp_joined, '\n');
	free(tmp_joined);
	return (TRUE);
}

int	parse_map(t_parse *parsing)
{
	int	return_value;

	if (!get_map(parsing))
		return (12);
	debug_print(PARSE_GET_MAP_SPLITTED, (void *)parsing->map);
	return_value = check_map_content(parsing->map);
	return (return_value);
}
