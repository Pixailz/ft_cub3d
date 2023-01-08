/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:16:28 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 19:39:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_return_value	set_error_known_type(int line_type, t_return_value return_value)
{
	t_error	*error;

	error = get_error(0);
	error->args |= return_value;
	if (return_value & ERRN_06)
		set_error_already_provided(line_type, &error->texture);
	else if (return_value & ERRN_07)
		set_error_wrong_sep(line_type, &error->texture);
	else if (return_value & ERRN_08)
		set_error_have_empty(line_type, &error->texture);
	else if (return_value & ERRN_09)
		set_error_wrong_path(line_type, &error->texture);
	else if (return_value & ERRN_10)
		set_error_wrong_color(line_type, error);
	else if (return_value & ERRN_11)
		set_error_wrong_color(line_type, error);
	else if (return_value & ERRN_12)
		set_error_wrong_color(line_type, error);
	return (return_value);
}
