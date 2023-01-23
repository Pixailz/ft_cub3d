/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:26:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 01:57:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

t_bool	get_map_end(t_error *err, char **tmp_joined, t_parse *parse)
{
	if (!ft_strlen(*tmp_joined))
	{
		free(*tmp_joined);
		return (FALSE);
	}
	parse->map.matrix = ft_cub3d_split(*tmp_joined, '\n');
	if (!parse->map.matrix)
	{
		set_error(err, 0, ERRN_03);
		return (FALSE);
	}
	free(*tmp_joined);
	return (TRUE);
}

t_bool	get_map(t_error *err, t_parse *parse)
{
	char	*tmp_line;
	char	*tmp_joined;
	int		gnl_status;

	tmp_joined = (char *)ft_calloc(sizeof(char), 1);
	if (!tmp_joined)
		return (set_error(err, 0, ERRN_03));
	while (TRUE)
	{
		tmp_line = ft_get_next_line(parse->map.file.fd, &gnl_status);
		if (!*tmp_line)
			break ;
		tmp_joined = ft_memjoin(tmp_joined, tmp_line);
		free(tmp_line);
		if (!tmp_joined)
			return (set_error(err, 0, ERRN_03));
	}
	if (tmp_line)
		free(tmp_line);
	return (get_map_end(err, &tmp_joined, parse));
}

t_r_value	parse_map(t_error *err, t_parse *parse)
{
	t_r_value	return_value;
	t_bool		have_error_get_map;

	have_error_get_map = get_map(err, parse);
	if (have_error(*err, 1))
		return (1);
	else if (!have_error_get_map)
		return (set_error(err, 1, ERRN_13));
	return_value = check_map_content(&parse->map, err);
	return (return_value);
}
