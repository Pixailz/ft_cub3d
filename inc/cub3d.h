/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/22 08:22:19 by brda-sil         ###   ########.fr       */
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
	int				file;
	unsigned char	floor[3];
	unsigned char	ceiling[3];
	int				north_file;
	int				south_file;
	int				west_file;
	int				east_file;
}				t_config;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// error/parse_error.c
int		parsing_error(int return_code);

// free/free.c
int		free_entry(t_config *main);

// init_entry.c
int		init_entry(t_config *main);

// main.c

// parse/parse_entry.c
int		parse_entry(char *filename, t_config *main);
int		parse_filename(char *filename);

// parse/parse_file.c
char	*get_line(int file);
int		check_permission(char *filename);
int		parse_file(char *filename, t_config *main);
int		parse_file_content(int file, t_config *main);

// parse/parse_line.c
int		parse_get_line_type(char *line);
int		parse_is_good_line(char *line, t_config *main);
int		parse_line(char *line, t_config *main);
t_bool	parse_is_line_already_taken(int already_taken, int line_type);

// parse/parse_line_color.c
int		parse_line_color(char *line, int line_type, t_config *main);
t_bool	check_line_color(char *ptr, int line_type, t_config *main);

// parse/parse_line_texture.c
int		parse_line_texture(char *line, int line_type, t_config *main);

/* ########################################################################## */

#endif
