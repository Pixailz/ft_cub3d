/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 16:03:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_line_color(char *ptr, int line_type, t_parse *main)
{
	char	**color;
	int		tmp_number;
	int		counter;
	int		has_overflow;

	color = ft_split(ptr, ',');
	counter = 0;
	while (counter < 3)
		if (!ft_is_str(color[counter++], ft_isdigit))
			return (10);
	counter = 0;
	while (counter < 3)
	{
		tmp_number = ft_patoi(color[counter], &has_overflow);
		if (has_overflow || tmp_number < 0 || tmp_number > 255)
			return (11);
		if (line_type == (1 << 4))
			main->floor[counter] = tmp_number;
		else
			main->ceiling[counter] = tmp_number;
		counter++;
	}
	ft_free_char_pp(color);
	return (0);
}

int	parse_line_color(char *line, int line_type, t_parse *main)
{
	char	*ptr;
	int		return_value;

	if (line[1] != ' ')
		return (7);
	else if (ft_is_str(line + 2, ft_is_space))
		return (8);
	ptr = line + 1;
	while (ft_isblank(*ptr))
		ptr++;
	if (ft_get_words(ptr, ',') != 3)
		return (9);
	return_value = check_line_color(ptr, line_type, main);
	if (return_value)
		return (return_value);
	return (0);
}
