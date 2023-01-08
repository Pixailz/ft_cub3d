/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.line.color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 21:43:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_line_color(char *ptr, int line_type, t_parse *parsing)
{
	char	**color;
	int		counter;
	int		has_overflow;
	int		tmp_number;

	color = ft_split(ptr, ',');
	counter = 0;
	while (counter < 3)
		if (!ft_is_str(color[counter++], ft_isdigit))
			set_error_known_type(line_type, ERRN_11);
	counter = 0;
	while (counter < 3)
	{
		tmp_number = ft_patoi(color[counter], &has_overflow);
		if (has_overflow || tmp_number < 0 || tmp_number > 255)
			set_error_known_type(line_type, ERRN_12);
		if (line_type == (1 << 4))
			parsing->texture.floor[counter++] = tmp_number;
		else
			parsing->texture.ceiling[counter++] = tmp_number;
	}
	ft_free_char_pp(color);
	return (0);
}

int	parse_line_color(char *line, int line_type, t_parse *parsing)
{
	char	*ptr;

	if (line[1] != ' ' && line[1] != 0)
		return (set_error_known_type(line_type, ERRN_07));
	else if (ft_is_str(line + 2, ft_is_space))
		return (set_error_known_type(line_type, ERRN_08));
	ptr = line + 1;
	while (ft_isblank(*ptr))
		ptr++;
	if (ft_get_words(ptr, ',') != 3)
		return (set_error_known_type(line_type, ERRN_10));
	if (check_line_color(ptr, line_type, parsing))
		return (1);
	return (0);
}
