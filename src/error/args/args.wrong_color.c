/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.wrong_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/11 22:29:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_args_color_format(t_r_value return_value)
{
	ft_putstr_fd(ERRN_PARAMS_STR_10, 2);
	if (return_value & ERRN_23)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_24)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_args_color_non_numeric(t_r_value return_value)
{
	ft_putstr_fd(ERRN_PARAMS_STR_11, 2);
	if (return_value & ERRN_25)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_26)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_args_color_wrong_number(t_r_value return_value)
{
	ft_putstr_fd(ERRN_PARAMS_STR_12, 2);
	if (return_value & ERRN_27)
		ft_putstr_fd(" (F)", 2);
	if (return_value & ERRN_28)
		ft_putstr_fd(" (C)", 2);
	ft_putchar_fd('\n', 2);
}

void	error_print_args_wrong_color(t_error *error)
{
	if (error->params & ERRN_10)
		error_print_args_color_format(error->texture);
	if (error->params & ERRN_11)
		error_print_args_color_non_numeric(error->texture);
	else if (error->params & ERRN_12)
		error_print_args_color_wrong_number(error->texture);
}

void	set_error_wrong_color(int line_type, t_error *error)
{
	if (error->params & ERRN_10)
	{
		if (line_type == FLOOR)
			error->texture |= ERRN_23;
		else if (line_type == CEIL)
			error->texture |= ERRN_24;
	}
	else if (error->params & ERRN_11)
	{
		if (line_type == FLOOR)
			error->texture |= ERRN_25;
		else if (line_type == CEIL)
			error->texture |= ERRN_26;
	}
	else if (error->params & ERRN_12)
	{
		if (line_type == FLOOR)
			error->texture |= ERRN_27;
		else if (line_type == CEIL)
			error->texture |= ERRN_28;
	}
}
