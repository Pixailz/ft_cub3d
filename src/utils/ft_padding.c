/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:31:22 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/12 20:52:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_size	ft_put_padded(int fd, t_size lvl)
{
	t_size	writed;

	writed = 0;
	lvl++;
	while (--lvl)
		writed += ft_putstr_fd(PADDING_CHAR, fd);
	return (writed);
}

t_size	ft_put_padded_str(int fd, t_size lvl, const char *str)
{
	int		save;
	t_size	writed;
	char	*ptr;

	writed = 0;
	lvl++;
	save = lvl;
	ptr = (char *)str;
	while (*ptr)
	{
		while (--lvl)
			writed += ft_putstr_fd(PADDING_CHAR, fd);
		lvl = save;
		while (*ptr && *ptr != '\n')
			writed += ft_putchar_fd(*ptr++, fd);
		if (*ptr)
			writed += ft_putchar_fd(*ptr++, fd);
	}
	writed += ft_putchar_fd('\n', fd);
	return (writed);
}
