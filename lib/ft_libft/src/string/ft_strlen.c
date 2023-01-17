/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:56:04 by pix               #+#    #+#             */
/*   Updated: 2023/01/18 00:17:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * @brief			Calculate the length of a string
 *
 * @param str		String to mesure
 *
 * @return (int)	Length of the strings
 */
int	ft_strlen(const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	if (!tmp)
		return (0);
	while (*tmp)
		tmp++;
	return (tmp - str);
}
