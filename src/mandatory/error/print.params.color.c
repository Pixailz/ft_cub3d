/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.params.color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 10:04:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	error_print_params_color_format(t_r_value return_value)
{
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_PARAMS_STR_10, 2);
	if (return_value & ERRN_23)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_24)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_color_non_numeric(t_r_value return_value)
{
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_PARAMS_STR_11, 2);
	if (return_value & ERRN_25)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_26)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_color_wrong_number(t_r_value return_value)
{
	ft_put_padded(2, 2);
	ft_putstr_fd(ERRN_PARAMS_STR_12, 2);
	if (return_value & ERRN_27)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_28)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_params_wrong_color(t_error err)
{
	if (err.params & ERRN_10)
		error_print_params_color_format(err.params_args);
	if (err.params & ERRN_11)
		error_print_params_color_non_numeric(err.params_args);
	if (err.params & ERRN_12)
		error_print_params_color_wrong_number(err.params_args);
}
