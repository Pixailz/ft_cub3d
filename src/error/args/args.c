/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_r_value	set_error_params_args(int line_type, t_r_value return_value)
{
	t_error	*error;

	error = get_error();
	error->params |= return_value;
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

void	error_print_params_known_type(t_error *error)
{
	ft_putstr_fd("Params:\n", 2);
	if (error->params & ERRN_06)
		error_print_params_already_provided(error->texture);
	if (error->params & ERRN_07)
		error_print_params_wrong_sep(error->texture);
	if (error->params & ERRN_08)
		error_print_params_have_empty(error->texture);
	if (error->params & ERRN_09)
		error_print_params_wrong_path(error->texture);
	if (error->params & ERRN_10 || error->params & ERRN_11 || \
														error->params & ERRN_12)
		error_print_params_wrong_color(error);
}

void	error_print_params(t_error *error)
{
	t_r_value	have_map_error;
	t_r_value	have_know_type_error;

	have_know_type_error = error->params & KNOW_TYPE_MASK;
	have_map_error = error->params & MAP_ERROR_MASK;
	if (!have_map_error && !have_know_type_error)
		ft_putstr_fd("Args:\n", 2);
	if (error->params & ERRN_01)
		ft_putendl_fd(ERRN_PARAMS_STR_01, 2);
	if (error->params & ERRN_02)
		ft_putendl_fd(ERRN_PARAMS_STR_02, 2);
	if (error->params & ERRN_03)
		ft_printf_fd(2, "%s (argv[1])\n", strerror(errno));
	if (error->params & ERRN_04)
		ft_putendl_fd(ERRN_PARAMS_STR_04, 2);
	if (error->params & ERRN_05)
		ft_putendl_fd(ERRN_PARAMS_STR_05, 2);
	if (have_know_type_error)
		error_print_params_known_type(error);
	if (have_map_error)
		error_print_params_map(error);
	if (!have_map_error && !have_know_type_error)
		ft_putchar_fd('\n', 2);
}
