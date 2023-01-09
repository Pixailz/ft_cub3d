/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/09 01:42:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_known_type(t_error *error)
{
	ft_putstr_fd("Params:\n", 2);
	if (error->args & ERRN_06)
		error_print_args_already_provided(error->texture);
	if (error->args & ERRN_07)
		error_print_args_wrong_sep(error->texture);
	if (error->args & ERRN_08)
		error_print_args_have_empty(error->texture);
	if (error->args & ERRN_09)
		error_print_args_wrong_path(error->texture);
	if (error->args & ERRN_10 || error->args & ERRN_11 || error->args & ERRN_12)
		error_print_args_wrong_color(error);
}

void	error_print_args(t_error *error)
{
	t_return_value	have_map_error;
	t_return_value	have_know_type_error;

	have_know_type_error = error->args & KNOW_TYPE_MASK;
	have_map_error = error->args & MAP_ERROR_MASK;
	if (!have_map_error && !have_know_type_error)
		ft_putstr_fd("Args:\n", 2);
	if (error->args & ERRN_01)
		ft_putendl_fd(ERRN_ARGS_STR_01, 2);
	if (error->args & ERRN_02)
		ft_putendl_fd(ERRN_ARGS_STR_02, 2);
	if (error->args & ERRN_03)
		ft_printf_fd(2, "%s (argv[1])\n", strerror(errno));
	if (error->args & ERRN_04)
		ft_putendl_fd(ERRN_ARGS_STR_04, 2);
	if (error->args & ERRN_05)
		ft_putendl_fd(ERRN_ARGS_STR_05, 2);
	if (have_know_type_error)
		error_print_args_known_type(error);
	if (have_map_error)
		error_print_args_map(error);
	if (!have_map_error && !have_know_type_error)
		ft_putchar_fd('\n', 2);
}
