/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.known.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 09:19:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	error_print_params_already_provided(t_r_value return_value)
{
	ft_put_padded(2, 2);
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
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_PARAMS_STR_07, 2);
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
	ft_put_padded(2, 2);
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

void	error_print_params_wrong_path(t_r_value return_value, t_parse parse)
{
	if (return_value & ERRN_19)
		print_errno(parse.textures.north_file);
	if (return_value & ERRN_20)
		print_errno(parse.textures.south_file);
	if (return_value & ERRN_21)
		print_errno(parse.textures.west_file);
	if (return_value & ERRN_22)
		print_errno(parse.textures.east_file);
}

void	error_print_params_known(t_error err, t_parse parse)
{
	t_r_value	err_no;

	err_no = err.params;
	ft_put_padded_str(2, 1, "Params:");
	if (err_no & ERRN_06)
		error_print_params_already_provided(err.params_args);
	if (err_no & ERRN_07)
		error_print_params_wrong_sep(err.params_args);
	if (err_no & ERRN_08)
		error_print_params_have_empty(err.params_args);
	if (err_no & ERRN_09)
		error_print_params_wrong_path(err.params_args, parse);
	if (err_no & ERRN_10 || err_no & ERRN_11 || err_no & ERRN_12)
		error_print_params_wrong_color(err);
}
