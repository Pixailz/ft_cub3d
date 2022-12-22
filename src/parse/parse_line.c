/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:38:02 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:24:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_get_line_type(char *line)
{
	char	two_first_char[2];

	ft_strncpy(two_first_char, line, 2);
	if (!ft_strncmp(two_first_char, "NO", 2))
		return (1);
	else if (!ft_strncmp(two_first_char, "SO", 2))
		return (1 << 1);
	else if (!ft_strncmp(two_first_char, "WE", 2))
		return (1 << 2);
	else if (!ft_strncmp(two_first_char, "EA", 2))
		return (1 << 3);
	else if (!ft_strncmp(two_first_char, "F", 1))
		return (1 << 4);
	else if (!ft_strncmp(two_first_char, "C", 1))
		return (1 << 5);
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

int	parse_is_good_line(char *line, t_config *main)
{
	static int	already_taken = 0;
	int			line_type;

	if (ft_is_str(line, ft_isspace))
		return (1);
	else if (ft_isspace(line[0]))
		return (2);
	else
		line_type = parse_get_line_type(line);
	if (!line_type)
		return (3);
	if (parse_is_line_already_taken(already_taken, line_type))
		return (4);
	already_taken += line_type;
	if (line_type < (1 << 3))
	{
		if (parse_line_texture(line, line_type, main))
			return (5);
	}
	else
		if (parse_line_color(line, line_type, main))
			return (6);
	return (0);
}

int	parse_line(char *line, t_config *main)
{
	int	return_value;

	return_value = parse_is_good_line(line, main);
	if (return_value)
		return (return_value);
	return (0);
}
