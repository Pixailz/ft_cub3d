/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/04 19:28:37 by brda-sil         ###   ########.fr       */
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

# define GOOD_CHAR_MAP	" 10NSEW"
# define VOID_CHAR '.'

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
	PARSE_RETURN_VALUE,
	PARSE_LINE,
	PARSE_EMPTY_LINE,
	PARSE_PARAMS_DONE,
	PARSE_GET_MAP,
	PARSE_GET_MAP_SPLITTED,
	PARSE_GET_MAP_SURROUDED
};

enum e_param_type
{
	NORTH	= 1,
	SOUTH	= 1 << 1,
	WEST	= 1 << 2,
	EAST	= 1 << 3,
	FLOOR	= 1 << 4,
	CEIL	= 1 << 5,
	OTHER	= 0
};

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug.c
void	debug_print(int mode, void *ptr);

// debug/parsing.1.c
void	debug_print_parse(int mode, void *ptr);
void	debug_print_splitted(char **splitted);
void	debug_print_surrounded(char **splitted);

// error/parse_error.c
int		parsing_error(int return_code);
void	parsing_error_args(int return_code);
void	parsing_error_map(int return_code);
void	parsing_error_params(int return_code);
void	parsing_error_texture_type(int line_type);

// free/free.c
void	close_file(int fd);
void	free_close_file(t_parse *main);
void	free_entry(t_parse *main);

// init_entry.c
void	init_entry(t_parse *main);
void	init_file(t_parse *main);

// main.c

// parse/map/check.c
int		check_map_content(char **map);
int		check_map_player_char(char **map);
t_bool	check_map_new_line(char **map);
t_bool	check_map_wrong_char(char **map);

// parse/map/check.surrounded.c
t_bool	check_is_surrounded_char_4(int x, int y, char **map);
t_bool	check_is_surrounded_char_8(int x, int y, char **map);
t_bool	check_is_surrounded_map(char **map);
void	debug_print_coord_checked(int x, int y, char **map);

// parse/map/check_utils.c
char	**dup_map(char **map);
char	*dup_map_get_line(int width, char *line);
t_bool	map_char_is_player(char c);
void	get_map_size(int *height, int *width, char **map);

// parse/map/entry.c
int		parse_map(t_parse *main);
t_bool	get_map(t_parse *main);

// parse/map/ft_cub3d_split.c
char	**ft_cub3d_split(char *str, char delim);
char	**ft_cub3d_split_get_words(char *str, char delim, int len_tab);
char	*ft_cub3d_get_word(char **str, char delim);

// parse/parse_entry.c
int		parse_entry(char *filename, t_parse *main);
int		parse_file_name(char *filename);

// parse/parse_file.c
int		parse_file(char *filename, t_parse *main);
int		parse_file_params(t_parse *main);

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

// parse/utils.c
char	*get_line(int file);
int		check_permission(char *filename);

/* ########################################################################## */

#endif
