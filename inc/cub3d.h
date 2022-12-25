/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/12/23 13:41:52 by brda-sil         ###   ########.fr       */
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
#  define DEBUG 1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD 420
# endif

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_parse
{
	int				file;
	unsigned char	floor[3];
	unsigned char	ceiling[3];
	int				north_file;
	int				south_file;
	int				west_file;
	int				east_file;
	char			**map;
}				t_parse;

// typedef struct s_config
// {
// }				t_parse;

enum e_debug_type
{
	PARSE_LINE,
	PARSE_EMPTY_LINE
};

enum e_param_type
{
	NO	= 1,
	SO	= 1 << 1,
	WE	= 1 << 2,
	EA	= 1 << 3,
	F	= 1 << 4,
	C	= 1 << 5,
};

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug.c
void	debug_print(int mode, void *ptr);

// debug/parsing.1.c
void	debug_parse(char *ptr);

// error/parse_error.c
int		parsing_error(int return_code);
void	parsing_error_parameters(int return_code);
void	parsing_error_texture_type(int line_type);

// free/free.c
int		free_entry(t_parse *main);

// init_entry.c
void	init_entry(t_parse *main);

// main.c

// parse/parse_entry.c
int		parse_entry(char *filename, t_parse *main);
int		parse_file_name(char *filename);

// parse/parse_file.c
char	*get_line(int file);
int		check_permission(char *filename);
int		parse_file(char *filename, t_parse *main);
int		parse_file_map(t_parse *main);
int		parse_file_params(int file, t_parse *main);

// parse/parse_line.c
int		parse_get_line_type(char *line);
int		parse_is_good_line(char *line, t_parse *main);
int		parse_line(char *line, t_parse *main);
t_bool	parse_is_line_already_taken(int already_taken, int line_type);

// parse/parse_line_color.c
int		check_line_color(char *ptr, int line_type, t_parse *main);
int		parse_line_color(char *line, int line_type, t_parse *main);

// parse/parse_line_texture.c
int		parse_line_texture(char *line, int line_type, t_parse *main);
t_bool	ft_is_space(const char c);

// parce/parc_map.c
int parse_map(char *line, t_parse *main);

/* ########################################################################## */

#endif
