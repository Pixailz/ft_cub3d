/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:33:30 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 11:02:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.mandatory.h>

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

t_r_value	error_print(t_error err, t_main *config)
{
	t_r_value		have_error_question_mark;

	have_error_question_mark = have_error(err, 0);
	if (have_error_question_mark)
		ft_printf_fd(2, "Error\n");
	if (err.malloc != 0)
		error_print_malloc(err.malloc);
	if (err.params != 0)
		error_print_params(err);
	if (err.texture != 0)
		error_print_texture(err);
	if (config)
		free_config(config);
	return (have_error_question_mark);
}
