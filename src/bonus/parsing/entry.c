/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:20 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 12:59:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

/**
 * @brief			parse file, check for permission, get params, and get the
 * 					map. in this order
 *
 * @param [out] t_error*	err
 * @param [out] t_parse		parse
 * @param [in] char*		filename
 *
 * @return	Zero or non negative number on failed, -1 on success,
 */
int	parse_file(t_error *err, t_parse *parse, char *filename)
{
	int		return_value;

	return_value = 0;
	parse->map.file.fd = check_permission(filename);
	if (parse->map.file.fd < 0)
	{
		parse->map.file.err_no = errno;
		return (set_error(err, 1, ERRN_03));
	}
	return_value = parse_file_params(err, parse);
	if (return_value && return_value != -1)
		return (return_value);
	if (have_error(*err, 2))
		return (1);
	debug_print(PARSE_PARAMS_DONE, NULL);
	return_value = parse_map(err, parse);
	return (return_value);
}

/**
 * @brief	check file name, should be longer than 4 (.cub) and
 * 			the final 4 char should be ".cub".
 *
 * @param [out] t_error*	err
 * @param [int] char*		filename
 *
 * @return	return 0 if success, non zero on failed,
 * 			return value are the AND operation of the both error.
 */
int	parse_file_name(t_error *err, char *filename)
{
	int				file_name_len;
	t_r_value		return_value;

	file_name_len = ft_strlen(filename) - 4;
	return_value = 0;
	if (file_name_len < 0)
		return_value |= set_error(err, 1, ERRN_01);
	if (ft_strncmp(".cub", filename + file_name_len, 4))
		return_value |= set_error(err, 1, ERRN_02);
	return (return_value);
}

t_r_value	parse_entry(t_error *err, char *filename, t_parse *parse)
{
	char	**ptr;

	if (parse_file_name(err, filename))
		return (1);
	if (parse_file(err, parse, filename) != -1)
		return (1);
	ptr = dup_map_squared(parse->map, MAX_DOF);
	ft_free_char_pp(parse->map.matrix);
	parse->map.matrix = ptr;
	if (!parse->map.matrix)
		return (set_error(err, 0, ERRN_04));
	return (0);
}
