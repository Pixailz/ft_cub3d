/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:33:30 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 20:03:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_r_value	error_print(t_error err, t_main *config)
{
	t_r_value		have_error_question_mark;

	debug_print(ERROR_PRINT_ERRN, (void *)&err);
	have_error_question_mark = have_error(err, 0);
	if (have_error_question_mark)
		ft_printf_fd(2, "Error\n");
	if (err.malloc != 0)
		error_print_malloc(err.malloc);
	if (err.params != 0)
		error_print_params(err);
	if (err.texture != 0)
		error_print_texture(err);
	if (config)
		free_config(config);
	return (have_error_question_mark);
}
