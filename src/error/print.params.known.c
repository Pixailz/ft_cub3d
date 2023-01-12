/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.params.known.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 14:08:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_params_already_provided(t_r_value return_value)
{
	ft_putstr_fd(ERRN_PARAMS_STR_06, 2);
	if (return_value & ERRN_01)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_02)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_03)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_04)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_05)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_06)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_wrong_sep(t_r_value return_value)
{
	ft_printf_fd(2, ERRN_PARAMS_STR_07);
	if (return_value & ERRN_07)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_08)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_09)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_10)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_11)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_12)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_have_empty(t_r_value return_value)
{
	ft_putstr_fd(ERRN_PARAMS_STR_08, 2);
	if (return_value & ERRN_13)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_14)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_15)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_16)
		ft_putstr_fd(" (EA)", 2);
	if (return_value & ERRN_17)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_18)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_wrong_path(t_r_value return_value)
{
	ft_printf_fd(2, "%s", strerror(errno));
	if (return_value & ERRN_19)
		ft_putstr_fd(" (NO)", 2);
	if (return_value & ERRN_20)
		ft_putstr_fd(" (SO)", 2);
	if (return_value & ERRN_21)
		ft_putstr_fd(" (WE)", 2);
	if (return_value & ERRN_22)
		ft_putstr_fd(" (EA)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_known(t_error *error)
{
	t_r_value	err_no;

	err_no = error->params;
	ft_putstr_fd("Params:\n", 2);
	if (err_no & ERRN_06)
		error_print_params_already_provided(error->params_args);
	if (err_no & ERRN_07)
		error_print_params_wrong_sep(error->params_args);
	if (err_no & ERRN_08)
		error_print_params_have_empty(error->params_args);
	if (err_no & ERRN_09)
		error_print_params_wrong_path(error->params_args);
	if (err_no & ERRN_10 || err_no & ERRN_11 || err_no & ERRN_12)
		error_print_params_wrong_color(error);
}
