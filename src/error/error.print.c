/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:33:30 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_r_value	error_print(t_main *config)
{
	t_error			*error;
	t_r_value	have_error_question_mark;

	error = get_error();
	debug_print(ERROR_PRINT_ERRN, FT_NULL);
	have_error_question_mark = have_error(0);
	if (have_error_question_mark)
		ft_printf_fd(2, "Error\n");
	if (error->malloc != 0)
		error_print_malloc(error->malloc);
	if (error->params != 0)
		error_print_params(error);
	if (error->texture != 0)
		error_print_texture(error->texture);
	free_config(config);
	return (have_error_question_mark);
}
