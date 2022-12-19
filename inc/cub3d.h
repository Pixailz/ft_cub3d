/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/19 14:52:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "mlx.h"
# include "libft.h"
# include <errno.h>
# include <string.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG 0
# endif

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_config
{
	int		file;
}				t_config;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// free/free.c
int	free_entry(t_config *main);

// main.c

// parse/parse_error.c
int	parsing_error(int return_code);

// parse/parse_file.c
int	check_permission(char *filename);
int	parse_file(char *filename, t_config *main);
int	parse_file_content(int file, t_config *main);
int	parse_file_line(char *line);

// parse/parsing.c
int	parse(char *filename, t_config *main);
int	parse_filename(char *filename);

/* ########################################################################## */

#endif
