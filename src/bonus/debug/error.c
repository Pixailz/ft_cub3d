/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:03:19 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/20 19:37:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	debug_print_errn_binary(const char *title, t_int64 to_bin)
{
	t_size	len_to_bin;

	ft_printf_fd(DEBUG_FD, "%s :\n    ", title);
	len_to_bin = ft_unbrlen_base((void *)to_bin, "01");
	while (len_to_bin++ < ERRN_LENGTH)
		ft_putchar_fd('0', DEBUG_FD);
	ft_putnbr_base_fd(to_bin, "01", DEBUG_FD);
	ft_putchar_fd('\n', DEBUG_FD);
}

void	debug_print_errn(t_error *err)
{
	debug_print_errn_binary("Malloc", err->malloc);
	debug_print_errn_binary("Params", err->params);
	debug_print_errn_binary("Params (args)", err->params_args);
	debug_print_errn_binary("Texture", err->texture);
	debug_print_errn_binary("Texture (args)", err->texture_args);
}

void	debug_print_error(int mode, void *ptr)
{
	if (mode == ERROR_PRINT_ERRN)
		debug_print_errn((t_error *)ptr);
}
