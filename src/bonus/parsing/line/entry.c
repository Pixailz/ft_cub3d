/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:38:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/27 03:25:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

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

int	get_line_type(char *line)
{
	char	two_first_char[2];

	ft_strncpy(two_first_char, line, 2);
	if (!ft_strncmp(two_first_char, "NO", 2))
		return (NORTH);
	else if (!ft_strncmp(two_first_char, "SO", 2))
		return (SOUTH);
	else if (!ft_strncmp(two_first_char, "WE", 2))
		return (WEST);
	else if (!ft_strncmp(two_first_char, "EA", 2))
		return (EAST);
	else if (!ft_strncmp(two_first_char, "F", 1))
		return (FLOOR);
	else if (!ft_strncmp(two_first_char, "C", 1))
		return (CEIL);
	return (0);
}

t_bool	have_all_params(int already_taken)
{
	return (already_taken & FLOOR && already_taken & FLOOR && \
		already_taken & NORTH && already_taken & SOUTH && \
		already_taken & WEST && already_taken & EAST);
}

int	is_good_line(t_error *err, char *line, t_parse *parse)
{
	static unsigned char	already_taken = 0;
	t_param_type			line_type;
	int						return_value;

	if (ft_is_str(line, ft_isspace))
		return (1);
	line_type = get_line_type(line);
	parse->current_line = line;
	if (!line_type)
	{
		if (have_all_params(already_taken))
			return (-1);
		else
			return (set_error(err, 1, ERRN_05));
	}
	if (line_type & (FLOOR | CEIL) && already_taken & line_type)
		return (set_error_known(err, 0, ERRN_06, line_type));
	already_taken |= line_type;
	if (line_type <= EAST)
		return_value = parse_line_text(err, line, line_type, parse);
	else
		return_value = parse_line_color(err, line, line_type, parse);
	if (return_value)
		return (return_value);
	return (0);
}

int	parse_line(t_error *err, char **line, t_parse *parse)
{
	int	return_value;

	return_value = is_good_line(err, *line, parse);
	if (return_value)
		return (return_value);
	free(*line);
	*line = FT_NULL;
	return (0);
}
