/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_no_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:03:48 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 13:11:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

void	print_errno(t_file_l *text)
{
	t_file_l	*ptr;

	ptr = text;
	while (ptr)
	{
		if (ptr->file.err_no != 0 && ptr->file.err_no != 9)
		{
			ft_put_padded(2, 2);
			ft_printf_fd(2, "%s (%d) (%s)\n", strerror(ptr->file.err_no), \
			ptr->file.err_no, ptr->file.path);
		}
		ptr = ptr->next;
	}
}
