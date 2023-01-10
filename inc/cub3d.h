/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/10 15:25:43 by brda-sil         ###   ########.fr       */
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
/* sqrt()
 * double
 * float
 */
# include <math.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define WINDOW_TITLE_3D				"Supa Cub3D"
# define FULL_SCREEN					0
# define WINDOW_TITLE_RAYCAST			"Supa Cub3D - RayCasting"
# define DEFAULT_SCREEN_3D_X			1200
# define DEFAULT_SCREEN_3D_Y			800
# define DEFAULT_SCREEN_RAYCAST_X		500
# define DEFAULT_SCREEN_RAYCAST_Y		500

# define PLAYER_STEP					0.25

# define MINIMAP_CELL_SIZE				32
# define MINIMAP_PLAYER_SIZE			8
# define MINIMAP_WALL_PATH				"./rsc/xpm/minimap_wall_32x32.xpm"
# define MINIMAP_VOID_PATH				"./rsc/xpm/minimap_void_32x32.xpm"
# define MINIMAP_PLAYER_PATH			"./rsc/xpm/minimap_player_8x8.xpm"

# ifndef DEBUG
#  define DEBUG							1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD						420
# endif

# define GOOD_CHAR_MAP					" 10NSWE"
# define VOID_CHAR						'.'
# define ERRN_LENGTH					32
# define PADDING						16

typedef unsigned int					t_return_value;

# define KNOW_TYPE_MASK					0xfe0
# define MAP_ERROR_MASK					0x3f000
# define MLX_ERROR_MASK					0x7e

# define ERRN_MALLOC_STR_01	"inside gnl"
# define ERRN_MALLOC_STR_02	"init failed"
# define ERRN_MALLOC_STR_03	"window, 3D, init failed"
# define ERRN_MALLOC_STR_04	"window, RayCasting, init failed"
# define ERRN_MALLOC_STR_05	"load texture (NO)"
# define ERRN_MALLOC_STR_06	"load texture (SO)"
# define ERRN_MALLOC_STR_07	"load texture (WE)"
# define ERRN_MALLOC_STR_08	"load texture (EA)"

# define ERRN_ARGS_STR_01	"file path too short"
# define ERRN_ARGS_STR_02	"wrong file extension"
# define ERRN_ARGS_STR_04	"empty file (argv[1])"
# define ERRN_ARGS_STR_05	"unknown parameter"
# define ERRN_ARGS_STR_06	"parameter already provided"
# define ERRN_ARGS_STR_07	"wrong parameter seperator (spaces(' '), only)"
# define ERRN_ARGS_STR_08	"parameter cannot be empty"
# define ERRN_ARGS_STR_10	"wrong color format"
# define ERRN_ARGS_STR_11	"non numeric number provided"
# define ERRN_ARGS_STR_12	"wrong number"
# define ERRN_ARGS_STR_13	"no map provided"
# define ERRN_ARGS_STR_14	"contain empty line ('\\n' only)"
# define ERRN_ARGS_STR_15	"wrong char in map"
# define ERRN_ARGS_STR_16	"not surrounded"
# define ERRN_ARGS_STR_17	"map have multiple player"
# define ERRN_ARGS_STR_18	"don't have player"

// KEYBOARD
	// DEFAULT
# define KEY_A	0x61
# define KEY_W	0x77
# define KEY_S	0x73
# define KEY_D	0x64

	// ARROWa
# define KEY_RIGHT	0xff53
# define KEY_LEFT	0xff51

	// EXTRA
# define KEY_ESC	0xff1b

enum	e_errno
{
	ERRN_00 = 0,
	ERRN_01 = 1U,
	ERRN_02 = 1U << 1,
	ERRN_03 = 1U << 2,
	ERRN_04 = 1U << 3,
	ERRN_05 = 1U << 4,
	ERRN_06 = 1U << 5,
	ERRN_07 = 1U << 6,
	ERRN_08 = 1U << 7,
	ERRN_09 = 1U << 8,
	ERRN_10 = 1U << 9,
	ERRN_11 = 1U << 10,
	ERRN_12 = 1U << 11,
	ERRN_13 = 1U << 12,
	ERRN_14 = 1U << 13,
	ERRN_15 = 1U << 14,
	ERRN_16 = 1U << 15,
	ERRN_17 = 1U << 16,
	ERRN_18 = 1U << 17,
	ERRN_19 = 1U << 18,
	ERRN_20 = 1U << 19,
	ERRN_21 = 1U << 20,
	ERRN_22 = 1U << 21,
	ERRN_23 = 1U << 22,
	ERRN_24 = 1U << 23,
	ERRN_25 = 1U << 24,
	ERRN_26 = 1U << 25,
	ERRN_27 = 1U << 26,
	ERRN_28 = 1U << 27,
	ERRN_29 = 1U << 28,
	ERRN_30 = 1U << 29,
	ERRN_31 = 1U << 30,
	ERRN_32 = 1U << 31,
};

enum e_debug_type
{
	ERROR_PRINT_ERRN,
	PARSE_RETURN_VALUE,
	PARSE_LINE,
	PARSE_EMPTY_LINE,
	PARSE_PARAMS_DONE,
	PARSE_GET_MAP,
	PARSE_GET_MAP_SPLITTED,
	PARSE_MAP_COORD_CHECKED,
	PARSE_GET_MAP_SURROUDED,
	RENDER_SCREEN_SIZE,
	RENDER_KEY_PRESS,
	RENDER_KEY_RELEASE,
	RENDER_PLAYER
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
/* STRUCT */
/* ###### */

/* MALLOC
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = MALLOC_INSIDE_GNL
 * ERRN_02 = MLX_FAILED
 * ERRN_03 = MLX_WINDOW_3D_FAILED
 * ERRN_04 = MLX_WINDOW_RAY_FAILED
 * ERRN_05 = MLX_NORTH_TEXT
 * ERRN_06 = MLX_SOUTH_TEXT
 * ERRN_07 = MLX_WEST_TEXT
 * ERRN_08 = MLX_EAST_TEXT
 * ERRN_08 =
 * ERRN_09 =
 * ERRN_10 =
 * ERRN_11 =
 * ERRN_12 =
 * ERRN_13 =
 * ERRN_14 =
 * ERRN_15 =
 * ERRN_16 =
 *
 * ARGS
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = ARGS_FILE_NAME_TOO_SHORT
 * ERRN_02 = ARGS_FILE_WRONG_EXTENSION
 * ERRN_03 = ARGS_PATH_PERMISSION_DENIED-NOT_FOUND
 * ERRN_04 = PARAMS_ARG_1_EMPTY_FILE
 * ERRN_05 = PARAMS_UNKNOWN
 * ERRN_06 = PARAMS_HAVE_ALREADY_PROVIDED
 * ERRN_07 = PARAMS_HAVE_WRONG_SEP
 * ERRN_08 = PARAMS_HAVE_EMPTY
 * ERRN_09 = PARAMS_HAVE_WRONG_PATH
 * ERRN_10 = PARAMS_WRONG_COLOR_FORMAT
 * ERRN_11 = PARAMS_WRONG_COLOR_NON_NUMBER
 * ERRN_12 = PARAMS_WRONG_COLOR_WRONG_NUMBER
 * ERRN_13 = PARAMS_MAP_EMPTY
 * ERRN_14 = PARAMS_MAP_NEW_LINE
 * ERRN_15 = PARAMS_MAP_WRONG_CHAR
 * ERRN_16 = PARAMS_MAP_NOT_SURROUNDED
 * ERRN_17 = PARAMS_MAP_MULTIPLE_PLAYER
 * ERRN_18 = PARAMS_MAP_NO_PLAYER
 * ERRN_19 =
 * ERRN_20 =
 * ERRN_21 =
 * ERRN_22 =
 * ERRN_23 =
 * ERRN_24 =
 * ERRN_25 =
 * ERRN_26 =
 * ERRN_27 =
 * ERRN_28 =
 * ERRN_29 =
 * ERRN_30 =
 * ERRN_31 =
 * ERRN_32 =
 *
 * TEXTURE
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = PARAMS_NORTH_ALREADY_PROVIDED
 * ERRN_02 = PARAMS_SOUTH_ALREADY_PROVIDED
 * ERRN_03 = PARAMS_WEST_ALREADY_PROVIDED
 * ERRN_04 = PARAMS_EAST_ALREADY_PROVIDED
 * ERRN_05 = PARAMS_FLOOR_ALREADY_PROVIDED
 * ERRN_06 = PARAMS_CEILING_ALREADY_PROVIDED
 * ERRN_07 = PARAMS_NORTH_WRONG_SEP
 * ERRN_08 = PARAMS_SOUTH_WRONG_SEP
 * ERRN_09 = PARAMS_WEST_WRONG_SEP
 * ERRN_10 = PARAMS_EAST_WRONG_SEP
 * ERRN_11 = PARAMS_FLOOR_WRONG_SEP
 * ERRN_12 = PARAMS_CEILING_WRONG_SEP
 * ERRN_13 = PARAMS_NORTH_HAVE_EMPTY
 * ERRN_14 = PARAMS_SOUTH_HAVE_EMPTY
 * ERRN_15 = PARAMS_WEST_HAVE_EMPTY
 * ERRN_16 = PARAMS_EAST_HAVE_EMPTY
 * ERRN_17 = PARAMS_FLOOR_HAVE_EMPTY
 * ERRN_18 = PARAMS_CEILING_HAVE_EMPTY
 * ERRN_19 = PARAMS_NORTH_WRONG_PATH
 * ERRN_20 = PARAMS_SOUTH_WRONG_PATH
 * ERRN_21 = PARAMS_WEST_WRONG_PATH
 * ERRN_22 = PARAMS_EAST_WRONG_PATH
 * ERRN_23 = PARAMS_FLOOR_WRONG_COLOR_FORMAT
 * ERRN_24 = PARAMS_CEIL_WRONG_COLOR_FORMAT
 * ERRN_25 = PARAMS_FLOOR_WRONG_COLOR_NON_NUMBER
 * ERRN_26 = PARAMS_CEIL_WRONG_COLOR_NON_NUMBER
 * ERRN_27 = PARAMS_FLOOR_WRONG_COLOR_WRONG_NUMBER
 * ERRN_28 = PARAMS_CEIL_WRONG_COLOR_WRONG_NUMBER
 * ERRN_29 =
 * ERRN_30 =
 * ERRN_31 =
 * ERRN_32 =
 *
 * ""TEMPLATE""
 * ERRN_00 = ALL_GOOD
 * ERRN_01 =
 * ERRN_02 =
 * ERRN_03 =
 * ERRN_04 =
 * ERRN_05 =
 * ERRN_06 =
 * ERRN_07 =
 * ERRN_08 =
 * ERRN_09 =
 * ERRN_10 =
 * ERRN_11 =
 * ERRN_12 =
 * ERRN_13 =
 * ERRN_14 =
 * ERRN_15 =
 * ERRN_16 =
 * ERRN_17 =
 * ERRN_18 =
 * ERRN_19 =
 * ERRN_20 =
 * ERRN_21 =
 * ERRN_22 =
 * ERRN_23 =
 * ERRN_24 =
 * ERRN_25 =
 * ERRN_26 =
 * ERRN_27 =
 * ERRN_28 =
 * ERRN_29 =
 * ERRN_30 =
 * ERRN_31 =
 * ERRN_32 =
 */

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_error
{
	t_return_value	malloc;
	t_return_value	args;
	t_return_value	texture;
}					t_error;

typedef struct s_mlx_texture
{
	void		*ptr;
	int			len_x;
	int			len_y;
}			t_mlx_texture;

typedef struct s_mlx
{
	void			*ptr;
	void			*win_3d;
	int				screen_x;
	int				screen_y;
	void			*win_ray;
	t_mlx_texture	north_text;
	t_mlx_texture	south_text;
	t_mlx_texture	west_text;
	t_mlx_texture	east_text;
	t_mlx_texture	mini_wall;
	t_mlx_texture	mini_void;
	t_mlx_texture	mini_player;
}			t_mlx;

typedef struct s_file
{
	int			fd;
	char		*path;
}			t_file;

typedef struct s_texture
{
	short			floor[3];
	short			ceiling[3];
	t_file			north_file;
	t_file			south_file;
	t_file			west_file;
	t_file			east_file;
}			t_texture;

typedef struct s_parse
{
	t_file		map_file;
	char		**map;
	t_texture	texture;
}				t_parse;

typedef struct s_player
{
	t_pos	pos;
	float	angle;
}				t_player;

typedef struct s_main
{
	t_parse		parsing;
	t_mlx		mlx;
	t_player	player;
}				t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug.c
void			debug_print(int mode, void *ptr);

// debug/debug.error.c
void			debug_print_errn(void);
void			debug_print_errn_binary(const char *title, t_int64 to_bin);
void			debug_print_error(int mode);

// debug/debug.map.c
void			debug_print_coord_checked(int x, int y, char **map);

// debug/debug.parsing.c
void			debug_print_parse(int mode, void *ptr);
void			debug_print_splitted(char **splitted);
void			debug_print_surrounded(char **splitted);

// debug/debug.render.c
void			debug_print_key(int key_code);
void			debug_print_player_stat(t_player *player);
void			debug_print_render(int mode, void *ptr);
void			debug_print_screen_size(void *ptr);

// error/args/args.already_provided.c
void			error_print_args_already_provided(t_return_value return_value);
void			set_error_already_provided(int line_type, t_return_value *return_value);

// error/args/args.c
void			error_print_args(t_error *error);
void			error_print_args_known_type(t_error *error);

// error/args/args.have_empty.c
void			error_print_args_have_empty(t_return_value return_value);
void			set_error_have_empty(int line_type, t_return_value *return_value);

// error/args/args.map.c
void			error_print_args_map(t_error *error);

// error/args/args.wrong_color.c
void			error_print_args_color_format(t_return_value return_value);
void			error_print_args_color_non_numeric(t_return_value return_value);
void			error_print_args_color_wrong_number(t_return_value return_value);
void			error_print_args_wrong_color(t_error *error);
void			set_error_wrong_color(int line_type, t_error *error);

// error/args/args.wrong_path.c
void			error_print_args_wrong_path(t_return_value return_value);
void			set_error_wrong_path(int line_type, t_return_value *return_value);

// error/args/args.wrong_sep.c
void			error_print_args_wrong_sep(t_return_value return_value);
void			set_error_wrong_sep(int line_type, t_return_value *return_value);

// error/error.c
t_bool			have_error(int mode);
t_error			*get_error(void);
t_return_value	set_error(unsigned char mode, t_return_value return_value);
void			free_error(t_error *error);

// error/error.line.c
t_return_value	set_error_known_type(int line_type, t_return_value return_value);

// error/error.malloc.c
void			error_print_malloc(t_return_value return_value);

// error/error.mlx.c
void			error_print_mlx(t_return_value return_value);

// error/error.parsing.c
int				error_parsing(int return_code);
void			error_parsing_args(int return_code);
void			error_parsing_map(int return_code);
void			error_parsing_params(int return_code);
void			error_parsing_texture_type(int line_type);

// error/error.print.c
t_return_value	error_print(t_main *config);

// error/error.texture.c
void			error_print_texture(t_return_value return_value);

// main.c

// parse/map/check.c
int				check_map_content(char **map);
int				check_map_player_char(char **map);
t_bool			check_map_new_line(char **map);
t_bool			check_map_wrong_char(char **map);

// parse/map/check.surrounded.c
t_bool			check_is_surrounded_char_4(int x, int y, char **map);
t_bool			check_is_surrounded_char_8(int x, int y, char **map);
t_bool			check_is_surrounded_map(char **map);

// parse/map/check_utils.c
char			**dup_map(char **map);
char			*dup_map_get_line(int width, char *line);
t_bool			map_char_is_player(char c);
void			get_map_size(int *height, int *width, char **map);

// parse/map/entry.c
t_bool			get_map(t_parse *parsing);
t_return_value	parse_map(t_parse *parsing);

// parse/parse.entry.c
t_return_value	parse_entry(char *filename, t_parse *parsing);

// parse/parse.file.c
int				parse_file(char *filename, t_parse *parsing);
int				parse_file_name(char *filename);
t_bool			parse_file_is_empty(char **line, int fd);
t_return_value	parse_file_params(t_parse *parsing);

// parse/parse.line.c
int				parse_get_line_type(char *line);
int				parse_is_good_line(char *line, t_parse *parsing);
int				parse_line(char **line, t_parse *parsing);
t_bool			parse_is_line_already_taken(int already_taken, int line_type);

// parse/parse.line.color.c
int				check_line_color(char *ptr, int line_type, t_parse *parsing);
int				parse_line_color(char *line, int line_type, t_parse *parsing);

// parse/parse.line.texture.c
t_bool			ft_is_space(const char c);
t_return_value	parse_line_texture(char *line, int line_type, t_parse *parsing);

// utils/check_permission.c
int				check_permission(char *filename);

// utils/close_file.c
void			close_file(int fd);

// utils/config.c
void			free_config(t_main *config);
void			init_config(t_main *config);

// utils/draw.3d.c
int				draw_3d(t_main *config);
void			draw_3d_map(t_main *config);

// utils/draw.ray.c
int				draw_ray(t_main *config);
void			draw_map_point(t_main *config, char current_cell, int x, int y);
void			draw_player_angle(t_main *config);
void			draw_player_pos(t_main *config);
void			draw_ray_map(t_main *config);

// utils/draw_line.c
void			draw_line(t_mlx *mlx, t_pos begin, t_pos end, int color);

// utils/file.c
void			free_file(t_file *file);
void			init_file(t_file *file);
void			set_file(t_file *file, char *path, int fd);

// utils/ft_cub3d_split.c
char			**ft_cub3d_split(char *str, char delim);
char			**ft_cub3d_split_get_words(char *str, char delim, int len_tab);
char			*ft_cub3d_get_word(char **str, char delim);

// utils/ft_free_char_pointer.c
void			ft_free_char_pointer(char *ptr);

// utils/get_line.c
char			*parse_get_line(int file);

// utils/mlx.c
t_return_value	init_mlx(t_main *config);
void			free_mlx(t_mlx *mlx);
void			free_mlx_textures(t_mlx *mlx);
void			init_mlx_texture(t_mlx *mlx);

// utils/mlx.hook.3d.c
int				end_hook(t_mlx *mlx);
int				key_press_3d(int key_pressed, t_main *config);
void			init_mlx_hook_3d(t_main *config);

// utils/mlx.hook.ray.c
int				key_press_ray(int key_pressed, t_mlx *mlx);
void			init_mlx_hook_ray(t_main *config);

// utils/move.angle.c
void			key_press_move_angle_left(t_main *config);
void			key_press_move_angle_right(t_main *config);

// utils/move.dir.c
void			key_press_move_down(t_main *config);
void			key_press_move_left(t_main *config);
void			key_press_move_right(t_main *config);
void			key_press_move_up(t_main *config);

// utils/parsing.c
void			free_parsing(t_parse *parsing);
void			init_parsing(t_parse *parsing);

// utils/rendering.c
float			get_player_angle(char player_char);
t_return_value	init_rendering(t_main *config);
t_return_value	start_rendering(t_main *config);
void			get_player_pos(t_main *config);

// utils/texture.c
t_return_value	load_texture(t_mlx_texture *text, char *file_path, void *mlx);
t_return_value	load_textures(t_main *config);
void			free_textures(t_texture *texture);
void			init_textures(t_texture *texture);

/* ########################################################################## */

#endif
