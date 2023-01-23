/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/23 00:14:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

int	check_line_color(t_error *err, char *ptr, int type, t_parse *parse)
{
	char	**color;
	int		counter;
	int		has_overflow;
	int		tmp_number;

	color = ft_split(ptr, ',');
	if (!*color)
		return (set_error(err, 0, ERRN_02));
	counter = 0;
	while (counter < 3)
		if (!ft_is_str(color[counter++], ft_isdigit))
			set_error_known(err, 0, ERRN_11, type);
	counter = 0;
	while (counter < 3)
	{
		tmp_number = ft_patoi(color[counter], &has_overflow);
		if (has_overflow || tmp_number < 0 || tmp_number > 255)
			set_error_known(err, 0, ERRN_12, type);
		if (type == FLOOR)
			ft_int4_chg(&parse->textures.floor, ++counter, tmp_number);
		else
			ft_int4_chg(&parse->textures.ceiling, ++counter, tmp_number);
	}
	ft_free_char_pp(color);
	return (0);
}

int	parse_line_color(t_error *err, char *line, int type, t_parse *parse)
{
	char	*ptr;

	if (line[1] != ' ' && line[1] != 0)
		return (set_error_known(err, 0, ERRN_07, type));
	else if (ft_is_str(line + 2, ft_is_space))
		return (set_error_known(err, 0, ERRN_08, type));
	ptr = line + 1;
	while (ft_isblank(*ptr))
		ptr++;
	if (ft_get_words(ptr, ',') != 3)
		return (set_error_known(err, 0, ERRN_10, type));
	if (check_line_color(err, ptr, type, parse))
		return (2);
	return (0);
}
