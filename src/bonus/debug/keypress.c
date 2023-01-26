/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 06:10:31 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/25 06:15:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	debug_print_key_special(int key_code)
{
	if (key_code == KEY_RIGHT)
		return (ft_putstr_fd("(RIGHT)", DEBUG_FD));
	else if (key_code == KEY_LEFT)
		return (ft_putstr_fd("(LEFT)", DEBUG_FD));
	else if (key_code == KEY_LSHIFT)
		return (ft_putstr_fd("(LSHIFT)", DEBUG_FD));
	else if (key_code == KEY_TAB)
		return (ft_putstr_fd("(TAB)", DEBUG_FD));
	else if (key_code == KEY_ESC)
		return (ft_putstr_fd("(ESC)", DEBUG_FD));
	return (0);
}

int	debug_print_key_letter(int key_code)
{
	if (key_code == KEY_E)
		return (ft_putstr_fd("(E)", DEBUG_FD));
	else if (key_code == KEY_A)
		return (ft_putstr_fd("(A)", DEBUG_FD));
	else if (key_code == KEY_W)
		return (ft_putstr_fd("(W)", DEBUG_FD));
	else if (key_code == KEY_S)
		return (ft_putstr_fd("(S)", DEBUG_FD));
	else if (key_code == KEY_D)
		return (ft_putstr_fd("(D)", DEBUG_FD));
	return (0);
}

void	debug_print_key(int key_code)
{
	int	writed;

	writed = 0;
	ft_printf_fd(DEBUG_FD, "key_press [0x%x]\t", key_code);
	writed += debug_print_key_letter(key_code);
	writed += debug_print_key_special(key_code);
	if (!writed)
		ft_putstr_fd("( ??? )", DEBUG_FD);
	ft_putchar_fd('\n', DEBUG_FD);
}
