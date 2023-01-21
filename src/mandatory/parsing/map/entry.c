/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:26:12 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 19:44:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

t_bool	get_map(t_parse *parse)
{
	char	*tmp_line;
	char	*tmp_joined;
	int		gnl_status;

	tmp_joined = (char *)ft_calloc(sizeof(char), 1);
	while (TRUE)
	{
		tmp_line = ft_get_next_line(parse->map.file.fd, &gnl_status);
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
	parse->map.matrix = ft_cub3d_split(tmp_joined, '\n');
	free(tmp_joined);
	return (TRUE);
}

t_r_value	parse_map(t_error *err, t_parse *parse)
{
	t_r_value	return_value;

	if (!get_map(parse))
		return (set_error(err, 1, ERRN_13));
	return_value = check_map_content(&parse->map, err);
	return (return_value);
}
