/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:18:23 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/08 20:14:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_input.h"

static void	fill_buff(int fd, char **buff, int *status)
{
	char	*joined_tmp;
	char	*buff_tmp;
	t_size	readed;

	buff_tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff_tmp)
	{
		*status = 1;
		return ;
	}
	readed = 1;
	while (readed && !ft_strcchr(buff_tmp, '\n'))
	{
		readed = read(fd, buff_tmp, BUFFER_SIZE);
		buff_tmp[readed] = 0;
		joined_tmp = ft_strjoin(*buff, buff_tmp);
		free(*buff);
		*buff = joined_tmp;
		if (joined_tmp == FT_NULL)
		{
			*status = 1;
			return ;
		}
	}
	free(buff_tmp);
}

static void	push_buff(char **buff, t_size len_line, int *status)
{
	t_size	len_buff;
	t_size	len_new_buff;
	char	*new_buff;

	len_buff = ft_strlen(*buff);
	if (len_buff == len_line)
	{
		free(*buff);
		*buff = FT_NULL;
		*status = 2;
		return ;
	}
	len_new_buff = len_buff - len_line;
	new_buff = (char *)ft_calloc(sizeof(char), len_new_buff + 1);
	if (!new_buff)
	{
		*status = 1;
		return ;
	}
	ft_strncpy(new_buff, *buff + len_line, len_new_buff);
	free(*buff);
	*buff = new_buff;
}

static void	get_line(char **line, char **buff, int *status)
{
	char	*newline_ptr;
	t_size	len_line;

	newline_ptr = ft_strchr(*buff, '\n');
	if (!newline_ptr)
		len_line = ft_strlen(*buff);
	else
		len_line = (newline_ptr - *buff) + 1;
	*line = ft_calloc(sizeof(char), len_line + 1);
	if (!line)
	{
		*status = 1;
		return ;
	}
	ft_strncpy(*line, *buff, len_line);
	push_buff(buff, len_line, status);
}

static void	ft_flush_gnl(char **buff)
{
	int	counter;

	counter = 0;
	while (counter < MAX_FD)
	{
		if (buff[counter] != FT_NULL)
			free(buff[counter]);
		counter++;
	}
}

char	*ft_get_next_line(int fd, int *status)
{
	static char	*buff[MAX_FD] = {FT_NULL};
	char		*line;

	if (fd == -2)
	{
		ft_flush_gnl(&buff[0]);
		return (FT_NULL);
	}
	else if (fd == -1 || BUFFER_SIZE < 1)
		return (FT_NULL);
	if (buff[fd] == FT_NULL)
	{
		buff[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buff[fd])
		{
			*status = 1;
			return (FT_NULL);
		}
	}
	fill_buff(fd, &buff[fd], status);
	get_line(&line, &buff[fd], status);
	return (line);
}
