/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.line.color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 17:29:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_line_color(char *ptr, int type, t_parse *parsing)
{
	char	**color;
	int		counter;
	int		has_overflow;
	int		tmp_number;

	color = ft_split(ptr, ',');
	counter = 0;
	while (counter < 3)
		if (!ft_is_str(color[counter++], ft_isdigit))
			set_error_known(0, ERRN_11, type);
	counter = 0;
	while (counter < 3)
	{
		tmp_number = ft_patoi(color[counter], &has_overflow);
		if (has_overflow || tmp_number < 0 || tmp_number > 255)
			set_error_known(0, ERRN_12, type);
		if (type == FLOOR)
			parsing->textures.floor[counter++] = tmp_number;
		else
			parsing->textures.ceiling[counter++] = tmp_number;
	}
	ft_free_char_pp(color);
	return (0);
}

int	parse_line_color(char *line, int type, t_parse *parsing)
{
	char	*ptr;

	if (line[1] != ' ' && line[1] != 0)
		return (set_error_known(0, ERRN_07, type));
	else if (ft_is_str(line + 2, ft_is_space))
		return (set_error_known(0, ERRN_08, type));
	ptr = line + 1;
	while (ft_isblank(*ptr))
		ptr++;
	if (ft_get_words(ptr, ',') != 3)
		return (set_error_known(0, ERRN_10, type));
	if (check_line_color(ptr, type, parsing))
		return (2);
	return (0);
}