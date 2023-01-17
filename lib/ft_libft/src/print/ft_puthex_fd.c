/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:12:07 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/17 20:12:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_print.h"

int	ft_put_hex_fd(int n, char mode, int fd)
{
	char	*n_str;
	t_size	len_n_str;

	if (mode == 'x')
		n_str = ft_itoa_base(n, "0123456789abcdef");
	else
		n_str = ft_itoa_base(n, "0123456789ABCDEF");
	len_n_str = ft_putstr_fd(n_str, fd);
	free(n_str);
	return (len_n_str);
}
