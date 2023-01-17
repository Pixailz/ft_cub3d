/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:22:58 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 20:21:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error_print_params_map(t_r_value params)
{
	ft_put_padded_str(2, 1, "Map:");
	if (params & ERRN_13)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_13);
	if (params & ERRN_14)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_14);
	if (params & ERRN_15)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_15);
	if (params & ERRN_16)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_16);
	if (params & ERRN_17)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_17);
	if (params & ERRN_18)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_18);
}

void	error_print_base(t_r_value params)
{
	ft_put_padded_str(2, 1, "Base:");
	if (params & ERRN_01)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_01);
	if (params & ERRN_02)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_02);
	if (params & ERRN_03)
	{
		ft_put_padded(2, 2);
		ft_printf_fd(2, "%s (argv[1])\n", strerror(errno));
	}
	if (params & ERRN_04)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_04);
	if (params & ERRN_05)
		ft_put_padded_str(2, 2, ERRN_PARAMS_STR_05);
}

void	error_print_params(t_error err)
{
	t_r_value	have_base_error;
	t_r_value	have_known_error;
	t_r_value	have_map_error;

	have_base_error = err.params & ERRN_MASK_INPUT_USER;
	have_known_error = err.params & ERRN_MASK_KNOWN;
	have_map_error = err.params & ERRN_MASK_MAP;
	if (have_base_error)
		error_print_base(err.params);
	if (have_known_error)
		error_print_params_known(err);
	if (have_map_error)
		error_print_params_map(err.params);
}
