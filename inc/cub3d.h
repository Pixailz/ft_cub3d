/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/14 19:04:29 by brda-sil         ###   ########.fr       */
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

// DEBUG
# ifndef DEBUG
#  define DEBUG							1
# endif

# ifndef VERBOSE
#  define VERBOSE						1
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD						420
# endif

// MATH
# define DR								0.0174533
# define PI								3.1415926535
// 2xPI
# define PI2							6.2831853072
// (3xPI)/2
# define PI3							4.7123889804
// PI/2
# define PI4							1.5707963268

# define ADJUST_DELTA					5

// MLX
# define WINDOW_TITLE					"Supa Cub3D"
# define FULL_SCREEN					0
# define DEFAULT_SCREEN_X				1200
# define DEFAULT_SCREEN_Y				800

// RAYTRACING
# define CELL_SIZE						64

// PLAYER
# define PLAYER_STEP					0.25
# define PLAYER_ANGLE_SIZE				21
# define PLAYER_ANGLE_COLOR				0x00ff00
# define MAX_DOF						8
# define FOV							60
# define BIT_PREC						6
# define MATRIX_OFFSET					10

// minimap
# define MINI_PLAYER_SIZE			8
# define MINI_CELL_SIZE				32
# define MINI_WALL_PATH				"./rsc/xpm/minimap_wall_32x32.xpm"
# define MINI_VOID_PATH				"./rsc/xpm/minimap_void_32x32.xpm"
# define MINI_PLAYER_PATH			"./rsc/xpm/minimap_player_8x8.xpm"
# define MINI_HIT_PATH				"./rsc/xpm/minimap_hit_2x2.xpm"

# define PADDING_CHAR					"   "

# define GOOD_CHAR_MAP					" 10NSWE"
# define VOID_CHAR						'.'
# define WALL_CHAR						'1'
# define EMPTY_CHAR						'0'
# define PLAYER_CHAR					'P'
# define ERRN_LENGTH					32
# define PADDING						16

# define ERRN_MALLOC_STR_01		"inside gnl"

# define ERRN_PARAMS_STR_01		"file path too short"
# define ERRN_PARAMS_STR_02		"wrong file extension"
# define ERRN_PARAMS_STR_04		"empty file (argv[1])"
# define ERRN_PARAMS_STR_05		"unknown parameter"
# define ERRN_PARAMS_STR_06		"parameter already provided"
# define ERRN_PARAMS_STR_07		"wrong parameter seperator (spaces(' '), only)"
# define ERRN_PARAMS_STR_08		"parameter cannot be empty"
# define ERRN_PARAMS_STR_10		"wrong color format"
# define ERRN_PARAMS_STR_11		"non numeric number provided"
# define ERRN_PARAMS_STR_12		"wrong number"
# define ERRN_PARAMS_STR_13		"no map provided"
# define ERRN_PARAMS_STR_14		"contain empty line ('\\n' only)"
# define ERRN_PARAMS_STR_15		"wrong char in map"
# define ERRN_PARAMS_STR_16		"not surrounded"
# define ERRN_PARAMS_STR_17		"map have multiple player"
# define ERRN_PARAMS_STR_18		"don't have player"

# define ERRN_TEXTURE_STR_01	"init mlx failed"
# define ERRN_TEXTURE_STR_02	"init window failed"
# define ERRN_TEXTURE_STR_03	"load texture, not a valid xpm file"

// KEYBOARD
	// DEFAULT
# define KEY_A							0x61
# define KEY_W							0x77
# define KEY_S							0x73
# define KEY_D							0x64
# define KEY_R							0x72

	// ARROW
# define KEY_RIGHT						0xff53
# define KEY_LEFT						0xff51

	// EXTRA
# define KEY_ESC						0xff1b

# define ERROR_MASK_INPUT_USER			0x1f
# define ERROR_MASK_KNOWN		0xfe0
# define ERROR_MASK_MAP			0x3f000
# define TEXTURE_ERROR_WITH_ARG_MASK	0x6

typedef unsigned long					t_r_value;

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
	PARSE_MAP_SIZE,
	RENDER_SCREEN_SIZE,
	RENDER_KEY_PRESS,
	RENDER_KEY_RELEASE,
	RENDER_PLAYER,
	RENDER_LINE,
	RAY_HORIZONTAL,
	RAY_VERTICAL
};

typedef enum e_param_type
{
	OTHER		= 0,
	NORTH		= 1,
	SOUTH		= 1 << 1,
	WEST		= 1 << 2,
	EAST		= 1 << 3,
	FLOOR		= 1 << 4,
	CEIL		= 1 << 5,
	MAIN_WINDOW	= 1 << 6,
	MINI_VOID	= 1 << 7,
	MINI_WALL	= 1 << 8,
	MINI_PLAYER	= 1 << 9,
	MINI_HIT	= 1 << 10
}			t_param_type;

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

/* MALLOC
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = MALLOC_INSIDE_GNL
 * ERRN_02 =
 * ERRN_03 =
 * ERRN_04 =
 * ERRN_05 =
 * ERRN_06 =
 * ERRN_07 =
 * ERRN_08 =
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
 * PARAMS
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
 * # PARAMS_ARGS
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
 * TEXTURES
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = MLX_INIT_FAILED
 * ERRN_02 = MLX_WINDOW_MAIN_FAILED
 * ERRN_03 = MLX_XPM_TO_IMAGE_FAILED
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
 *
 * TEXTURES_ARGS
 * ERRN_00 = ALL_GOOD
 * ERRN_01 = MLX_MAIN_WINDOW
 * ERRN_02 = MLX_NORTH_TEXT
 * ERRN_03 = MLX_SOUTH_TEXT
 * ERRN_04 = MLX_WEST_TEXT
 * ERRN_05 = MLX_EAST_TEXT
 * ERRN_06 = MLX_MINI_VOID_TEXT
 * ERRN_07 = MLX_MINI_WALL_TEXT
 * ERRN_08 = MLX_MINI_PLAYER_TEXT
 * ERRN_09 = MLX_MINI_HIT_TEXT
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

typedef struct s_error
{
	t_r_value	malloc;
	t_r_value	params;
	t_r_value	params_args;
	t_r_value	texture;
	t_r_value	texture_args;
}					t_error;

typedef struct s_f_pos
{
	float	x;
	float	y;
}			t_f_pos;

typedef struct s_i_pos
{
	int	x;
	int	y;
}		t_i_pos;

typedef struct s_line
{
	t_f_pos	begin;
	t_f_pos	end;
}				t_line;

typedef struct s_mlx_texture
{
	void		*ptr;
	char		*buff;
	int			bpp;
	int			endian;
	int			size_line;
	t_i_pos		len;
}			t_mlx_texture;

typedef struct s_ray
{
	int				nbr;
	int				id;
	t_bool			hit;
	int				depth_of_field;
	t_f_pos			pos;
	t_f_pos			offset;
	t_f_pos			save;
	float			dist;
	float			angle;
	float			a_tan;
	float			n_tan;
	t_i_pos			max;
	t_i_pos			t;
	t_mlx_texture	img_use;
}					t_ray;

typedef struct s_mlx_textures
{
	t_mlx_texture	north;
	t_mlx_texture	south;
	t_mlx_texture	west;
	t_mlx_texture	east;
	t_mlx_texture	mini_wall;
	t_mlx_texture	mini_void;
	t_mlx_texture	mini_player;
	t_mlx_texture	mini_hit;
}					t_mlx_textures;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	t_i_pos			screen;
	t_mlx_textures	textures;
}					t_mlx;

typedef struct s_file
{
	int			fd;
	char		*path;
}			t_file;

typedef struct s_textures
{
	short			floor[3];
	short			ceiling[3];
	t_file			north_file;
	t_file			south_file;
	t_file			west_file;
	t_file			east_file;
}			t_textures;

typedef struct s_map
{
	t_file		file;
	t_i_pos		size;
	char		**matrix;
}				t_map;

typedef struct s_parse
{
	t_map		map;
	t_textures	textures;
}				t_parse;

typedef struct s_player
{
	t_f_pos	pos;
	t_f_pos	delta;
	float	angle;
}				t_player;

typedef struct s_main
{
	t_parse		parsing;
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	t_error		err;
}				t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// debug/debug.c
void		debug_print(int mode, void *ptr);

// debug/debug.error.c
void		debug_print_errn(t_error *err);
void		debug_print_errn_binary(const char *title, t_int64 to_bin);
void		debug_print_error(int mode, void *ptr);

// debug/debug.map.c
void		debug_print_coord_checked(int x, int y, char **map);

// debug/debug.parsing.c
void		debug_print_map_size(t_map *map);
void		debug_print_parse(int mode, void *ptr);
void		debug_print_splitted(char **splitted);
void		debug_print_surrounded(char **splitted);

// debug/debug.ray.c
void		debug_print_ray(int mode, void *ptr);
void		debug_print_ray_info(char *title, t_ray ray);

// debug/debug.render.c
void		debug_print_key(int key_code);
void		debug_print_player_stat(t_player *player);
void		debug_print_render(int mode, void *ptr);
void		debug_print_screen_size(void *ptr);

// debug/debug.render.line.c
void		debug_print_line_pos(t_line *line);

// draw/base.c
void		draw_base(t_main *config);

// draw/line.c
t_line		get_line(t_f_pos begin, t_f_pos end);
void		draw_line(void *mlx_ptr, void *win_ptr, t_line line, int color);

// draw/minimap.c
void		draw_map(t_main *config);
void		draw_map_point(t_main *config, char current_cell, int y, int x);
void		draw_minimap(t_main *config);
void		draw_player_angle(t_main *config);
void		draw_player_pos(t_main *config);

// draw/ray.c
void		draw_fov(t_main *config);
void		draw_ray_hit(t_main *config);

// error/error.c
t_bool		have_error(t_error err, int mode);
void		init_error(t_error *err);

// error/print.c
t_r_value	error_print(t_error err, t_main *config);

// error/print.malloc.c
void		error_print_malloc(t_r_value return_value);

// error/print.params.c
void		error_print_base(t_r_value params);
void		error_print_params(t_error err);
void		error_print_params_map(t_r_value params);

// error/print.params.color.c
void		error_print_params_color_format(t_r_value return_value);
void		error_print_params_color_non_numeric(t_r_value return_value);
void		error_print_params_color_wrong_number(t_r_value return_value);
void		error_print_params_wrong_color(t_error err);

// error/print.params.known.c
void		error_print_params_already_provided(t_r_value return_value);
void		error_print_params_have_empty(t_r_value return_value);
void		error_print_params_known(t_error err);
void		error_print_params_wrong_path(t_r_value return_value);
void		error_print_params_wrong_sep(t_r_value return_value);

// error/print.texture.c
void		error_print_texture(t_error err);

// error/print.texture.known.c
void		error_print_texture_known(t_error err);
void		error_print_texture_load(t_error err);
void		error_print_texture_window(t_error err);

// error/set.c
t_r_value	set_error(t_error *err, unsigned char mode, t_r_value return_value);
t_r_value	set_error_known(t_error *err, int mode, t_r_value err_no, int type);
t_r_value	set_error_known_params(t_error *err, t_r_value err_no, int type);
t_r_value	set_error_known_texture(t_error *err, t_r_value err_no, int type);

// error/set.params.c
void		set_error_already_provided(int type, t_r_value *return_value);
void		set_error_have_empty(int type, t_r_value *return_value);
void		set_error_wrong_color(t_r_value err_no, int type, t_r_value *param_args);
void		set_error_wrong_path(int type, t_r_value *return_value);
void		set_error_wrong_sep(int type, t_r_value *return_value);

// error/set.texture.c
t_r_value	set_error_mlx_texture(t_param_type type, t_r_value *return_value);
t_r_value	set_error_mlx_window(t_param_type type, t_r_value *return_value);

// main.c

// parse/map/check.c
int			check_map_content(t_map *map, t_error *err);
int			check_map_player_char(t_map map, t_error *err);
t_bool		check_map_new_line(t_map map);
t_bool		check_map_wrong_char(t_map map);

// parse/map/check.surrounded.c
t_bool		check_is_surrounded_char_4(int x, int y, char **map);
t_bool		check_is_surrounded_char_8(int x, int y, char **map);
t_bool		check_is_surrounded_map(t_map *map);

// parse/map/check_utils.c
char		**dup_map_surrounded(t_map map);
char		*dup_map_get_line(int width, char *line);
t_bool		map_char_is_player(char c);
void		get_map_size(t_map *map);

// parse/map/entry.c
t_bool		get_map(t_parse *parsing);
t_r_value	parse_map(t_error *err, t_parse *parsing);

// parse/parse.entry.c
t_r_value	parse_entry(t_error *err, char *filename, t_parse *parsing);

// parse/parse.file.c
int			parse_file(t_error *err, char *filename, t_parse *parsing);
int			parse_file_name(t_error *err, char *filename);
t_bool		parse_file_is_empty(t_error *err, char **line, int fd);
t_r_value	parse_file_params(t_error *err, t_parse *parsing);

// parse/parse.line.c
int			parse_get_line_type(char *line);
int			parse_is_good_line(t_error *err, char *line, t_parse *parsing);
int			parse_line(t_error *err, char **line, t_parse *parsing);
t_bool		parse_is_line_already_taken(int already_taken, int line_type);

// parse/parse.line.color.c
int			check_line_color(t_error *err, char *ptr, int type, t_parse *parsing);
int			parse_line_color(t_error *err, char *line, int type, t_parse *parsing);

// parse/parse.line.texture.c
t_bool		ft_is_space(const char c);
t_r_value	parse_line_text(t_error *err, char *line, int type, t_parse *parsing);

// ray/cast.c
void		cast_ray_entry(t_main *config);
void		cast_rays(float angle, t_main *config);
void		choose_ray(t_main *config);

// ray/horizontal.c
void		cast_ray_down(t_ray *ray, t_player player);
void		cast_ray_horizontal(t_ray *ray, t_player player, t_map map);
void		cast_ray_up(t_ray *ray, t_player player);

// ray/init.c
void		init_ray(float player_angle, t_ray *ray);

// ray/utils.1.c
float		get_a_tan(float ray_angle);
float		get_dist(t_player player, t_ray ray);
float		get_n_tan(float ray_angle);
t_bool		ray_hit(t_ray *ray, t_map map, int to_add);
void		increase_offset(t_ray *ray);

// ray/vertical.c
void		cast_ray_left(t_ray *ray, t_player player);
void		cast_ray_rigth(t_ray *ray, t_player player);
void		cast_ray_vertical(t_ray *ray, t_player player, t_map map);

// utils/check_permission.c
int			check_permission(char *filename);

// utils/close_file.c
void		close_file(int fd);

// utils/config.c
void		free_config(t_main *config);
void		init_config(t_main *config);

// utils/file.c
void		free_file(t_file *file);
void		init_file(t_file *file);
void		set_file(t_file *file, char *path, int fd);

// utils/ft_cub3d_split.c
char		**ft_cub3d_split(char *str, char delim);
char		**ft_cub3d_split_get_words(char *str, char delim, int len_tab);
char		*ft_cub3d_get_word(char **str, char delim);

// utils/ft_free_char_pointer.c
void		ft_free_char_pointer(char *ptr);

// utils/ft_padding.c
t_size		ft_put_padded(int fd, t_size lvl);
t_size		ft_put_padded_str(int fd, t_size lvl, const char *str);

// utils/get_line.c
char		*parse_get_line(t_error *err, int file);

// utils/get_ratio.c
float		get_ratio(float nbr);

// utils/mlx.c
t_r_value	init_mlx(t_main *config);
void		init_mlx_texture(t_mlx_texture *text);
void		init_mlx_textures(t_mlx_textures *textures);

// utils/mlx.free.c
void		free_mlx(t_mlx *mlx);
void		free_mlx_texture(void *mlx, t_mlx_texture *text);
void		free_mlx_textures(t_mlx *mlx);

// utils/mlx.hook.c
int			end_hook(t_mlx *mlx);
int			key_press(int key_code, t_main *config);
t_bool		is_movement_key(int key_code);
void		init_mlx_hook(t_main *config);
void		move(int key_code, t_main *config);

// utils/move.angle.c
void		adjust_delta(t_player *player);
void		key_press_move_angle_left(t_player *player);
void		key_press_move_angle_right(t_player *player);

// utils/move.dir.c
void		key_press_move_down(t_player *player);
void		key_press_move_left(t_player *player);
void		key_press_move_right(t_player *player);
void		key_press_move_up(t_player *player);

// utils/parsing.c
void		free_parsing(t_parse *parsing);
void		init_parsing(t_parse *parsing);

// utils/player.c
void		init_player(t_player *player);

// utils/rendering.c
float		get_player_angle(char player_char);
t_r_value	init_rendering(t_main *config);
t_r_value	start_rendering(t_main *config);
void		get_player_pos(t_main *config);

// utils/texture.c
t_r_value	load_texture(t_mlx_texture *text, char *file_path, void *mlx);
t_r_value	load_textures(t_main *config);
void		free_textures(t_textures *textures);
void		init_textures(t_textures *texture);

/* ########################################################################## */

#endif
