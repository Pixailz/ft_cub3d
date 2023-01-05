/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:38:02 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/05 19:04:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_get_line_type(char *line)
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

t_bool	parse_is_line_already_taken(int already_taken, int line_type)
{
	int	counter;

	counter = 0;
	while (counter <= 5)
		if ((already_taken & (1 << counter++)) == line_type)
			return (TRUE);
	return (FALSE);
}

int	parse_is_good_line(char *line, t_parse *parsing)
{
	static unsigned char	already_taken = 0;
	int						line_type;
	int						return_value;

	if (ft_is_str(line, ft_isspace))
		return (1);
	line_type = parse_get_line_type(line);
	if (!line_type)
		return (5);
	if (parse_is_line_already_taken(already_taken, line_type))
		return (6);
	already_taken += line_type;
	if (line_type <= EAST)
		return_value = parse_line_texture(line, line_type, parsing);
	else
		return_value = parse_line_color(line, line_type, parsing);
	if (return_value)
		return (return_value);
	if (already_taken == (NORTH | SOUTH | WEST | EAST | FLOOR | CEIL))
		return (-1);
	return (0);
}

int	parse_line(char *line, t_parse *parsing)
{
	int	return_value;

	return_value = parse_is_good_line(line, parsing);
	if (return_value)
		return (return_value);
	return (0);
}
