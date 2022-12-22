/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:01:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:25:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_line_color(char *ptr, int line_type, t_config *main)
{
	char	**color;
	int		tmp_number;
	int		counter;
	int		has_overflow;

	color = ft_split(ptr, ',');
	counter = 0;
	while (counter < 3)
	{
		tmp_number = ft_patoi(color[counter], &has_overflow);
		if (has_overflow)
			return (FALSE);
		if (tmp_number < 0 || tmp_number > 255)
			return (FALSE);
		if (line_type == (1 << 4))
			main->floor[counter] = tmp_number;
		else
			main->ceiling[counter] = tmp_number;
		counter++;
	}
	ft_free_char_pp(color);
	return (TRUE);
}

int	parse_line_color(char *line, int line_type, t_config *main)
{
	char	*ptr;
	char	**color;

	if (!ft_isblank(line[1]))
		return (1);
	else if (ft_is_str(line + 1, ft_isblank))
		return (2);
	ptr = line + 2;
	while (ft_isblank(*ptr))
		ptr++;
	check_line_color(ptr, line_type, main);
	return (0);
}
