/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_no_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:03:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/21 03:15:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

void	print_errno(int err_no, char *filename)
{
	if (err_no != 0)
	{
		ft_put_padded(2, 2);
		ft_printf_fd(2, "%s (%d) (%s)\n", strerror(err_no), err_no, filename);
	}
}
