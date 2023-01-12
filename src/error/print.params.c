/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 14:00:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_params_map(t_error *error)
{
	ft_putendl_fd("Map:", 2);
	if (error->params & ERRN_13)
		ft_putendl_fd(ERRN_PARAMS_STR_13, 2);
	if (error->params & ERRN_14)
		ft_putendl_fd(ERRN_PARAMS_STR_14, 2);
	if (error->params & ERRN_15)
		ft_putendl_fd(ERRN_PARAMS_STR_15, 2);
	if (error->params & ERRN_16)
		ft_putendl_fd(ERRN_PARAMS_STR_16, 2);
	if (error->params & ERRN_17)
		ft_putendl_fd(ERRN_PARAMS_STR_17, 2);
	if (error->params & ERRN_18)
		ft_putendl_fd(ERRN_PARAMS_STR_18, 2);
}

void	error_print_params(t_error *error)
{
	t_r_value	have_error_with_args;
	t_r_value	have_map_error;

	have_error_with_args = error->params & PARAMS_ERROR_WITH_ARG_MASK;
	have_map_error = error->params & PARAMS_ERROR_MAP_MASK;
	if (!have_error_with_args && !have_map_error)
		ft_putstr_fd("Params:\n", 2);
	if (error->params & ERRN_01)
		ft_putstr_fd(ERRN_PARAMS_STR_01, 2);
	if (error->params & ERRN_02)
		ft_putstr_fd(ERRN_PARAMS_STR_02, 2);
	if (error->params & ERRN_03)
		ft_printf_fd(2, "%s (argv[1])", strerror(errno));
	if (error->params & ERRN_04)
		ft_putstr_fd(ERRN_PARAMS_STR_04, 2);
	if (error->params & ERRN_05)
		ft_putstr_fd(ERRN_PARAMS_STR_05, 2);
	if (have_error_with_args)
		error_print_params_known(error);
	if (have_map_error)
		error_print_params_map(error);
	if (!have_error_with_args && !have_map_error)
		ft_putchar_fd('\n', 2);
}
