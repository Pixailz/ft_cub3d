/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:04:55 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/26 10:32:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.bonus.h>

int	lstsize_file(t_file_l *lst)
{
	t_file_l	*ptr;
	int			size;

	ptr = lst;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

void	lstadd_front_file(t_file_l **lst, t_file_l *new)
{
	new->next = *lst;
	*lst = new;
}

t_file_l	*lstnew_file(t_error *err, char *path, int fd, int err_no)
{
	t_file_l	*ptr;

	ptr = (t_file_l *)ft_calloc(sizeof(t_file_l), 1);
	if (!ptr)
	{
		set_error(err, 0, ERRN_05);
		return (FT_NULL);
	}
	ptr->next = FT_NULL;
	set_file(&ptr->file, path, fd);
	ptr->file.err_no = err_no;
	return (ptr);
}
