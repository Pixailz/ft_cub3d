/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:48:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/29 15:22:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// int	ft_cub3d_split_get_word(char **str, char delim, char *encl)
// {
// 	int		have_encl;
// 	char	tmp_delim;
// 	char	*str_ptr;

// 	while (**str && **str == delim)
// 		(*str)++;
// 	str_ptr = *str;
// 	have_encl = ft_strcchr(encl, **str);
// 	if (have_encl)
// 	{
// 		tmp_delim = **str;
// 		str_ptr++;
// 		while (*str_ptr && *str_ptr != tmp_delim)
// 			str_ptr++;
// 		str_ptr++;
// 	}
// 	else
// 		while (*str_ptr && *str_ptr != delim && !ft_strcchr(encl, *str_ptr))
// 			str_ptr++;
// 	return (str_ptr - *str);
// }

char	*ft_cub3d_get_word(char **str, char delim)
{
	char	*newline_ptr;
	t_size	len_line;

	newline_ptr = ft_strchr(*str, delim);
	len_line = newline_ptr - *str;
	newline_ptr = ft_substr(*str, 0, len_line);
	*str = *str + len_line + 1;
	return (newline_ptr);
}

char	**ft_cub3d_split_get_words(char *str, char delim, int len_tab)
{
	int		counter;
	int		size;
	char	**tab;

	tab = (char **)ft_calloc(sizeof(char *), len_tab + 1);
	counter = 0;
	while (counter < len_tab)
	{
		tab[counter] = ft_cub3d_get_word(&str, delim);
		counter++;
	}
	tab[counter] = ft_strdup(str);
	tab[counter + 1] = FT_NULL;
	return (tab);
}

char	**ft_cub3d_split(char *str, char delim)
{
	char	**tab;
	char	*tmp_str;
	int		len_tab;

	if (!str)
		return (FT_NULL);
	tmp_str = ft_strtrim(str, (char *)&delim);
	len_tab = ft_strcchr(tmp_str, delim);
	tab = ft_cub3d_split_get_words(tmp_str, delim, len_tab);
	free(tmp_str);
	return (tab);
}
