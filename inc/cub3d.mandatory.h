/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.mandatory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:56:44 by brda-sil          #+#    #+#             */
/*   Updated: 2023/01/24 03:23:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MANDATORY_H
# define CUB3D_MANDATORY_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

/* mlx_destroy_image()
 * mlx_destroy_window()
 * mlx_put_image_to_window()
 * mlx_new_window()
 * mlx_get_data_addr()
 * mlx_xpm_file_to_image()
 * mlx_hook()
 * mlx_init()
 */
# include "mlx.h"
# include "libft.h"
/* strerror()
 */
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
#  define DEBUG							0
# endif

# ifndef VERBOSE
#  define VERBOSE						2
# endif

# ifndef DEBUG_FD
#  define DEBUG_FD						420
# endif

// MATH
	// ONE DEGREE
# define DR								0.0174533
	// PI, THE ONLY ONE
# define PI								3.1415926535
	// 2xPI
# define PI2							6.2831853072
	// (3xPI)/2
# define PI3							4.7123889804
	// PI/2
# define PI4							1.5707963268

// CONFIG

	// BASE
# define PLAYER_STEP					0.036
# define FOV							50

	// MATRIX
# define MAX_DOF						1
# define GOOD_CHAR_MAP					" 10NSWE"
# define VOID_CHAR						' '
# define WALL_CHAR						'1'
# define EMPTY_CHAR						'0'

		// WINDOW
# define WINDOW_TITLE					"Supa Cub3D"
# define FULL_SCREEN					0
# define SCREEN_SIZE_X					1024
# define SCREEN_SIZE_Y					576

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

	// RAYCAST

# define PLAYER_ANGLE_SIZE				16
# define PLAYER_ANGLE_COLOR				0x00ff00

		// WINDOW
# define RAY_TITLE					"Supa Cub3D - RayCasting"
# define RAY_ENABLE					1
# define RAY_SCREEN_SIZE_X			800
# define RAY_SCREEN_SIZE_Y			480

		// TEXTURE
# define RAY_WALL_PATH				"./rsc/xpm/minimap/wall_x16.xpm"
# define RAY_VOID_PATH				"./rsc/xpm/minimap/void_x16.xpm"
# define RAY_PLAYER_PATH			"./rsc/xpm/minimap/player_x4.xpm"
# define RAY_HIT_COLOR				0xff0000

// ERRNO
# define ERRN_LENGTH					32

	// MASK
# define ERRN_MASK_INPUT_USER			0x1f
# define ERRN_MASK_KNOWN				0xfe0
# define ERRN_MASK_MAP					0x3f000
# define ERRN_MASK_TEXTURE_ARG			0x6

	// STRING
# define PADDING_STR					"   "

		// MALLOC
# define ERRN_MALLOC_STR_01		"inside gnl"
# define ERRN_MALLOC_STR_02		"inside split"
# define ERRN_MALLOC_STR_03		"inside get_map()"
# define ERRN_MALLOC_STR_04		"inside dup_map_squared()"

		// PARAMS
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

		// TEXTURE
# define ERRN_TEXTURE_STR_01	"init mlx failed"
# define ERRN_TEXTURE_STR_02	"init window failed"
# define ERRN_TEXTURE_STR_03	"load texture"
# define ERRN_TEXTURE_STR_04	"load scene"

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT / DEFINE */
/* ############### */

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
	OTHER			= 0,
	NORTH			= 1,
	SOUTH			= 1 << 1,
	WEST			= 1 << 2,
	EAST			= 1 << 3,
	FLOOR			= 1 << 4,
	CEIL			= 1 << 5,
	MAIN_WINDOW		= 1 << 6,
	RAY_WINDOW		= 1 << 7,
	RAY_VOID		= 1 << 8,
	RAY_WALL		= 1 << 9,
	RAY_PLAYER		= 1 << 10
}	t_param_type;

typedef struct s_error
{
	t_r_value	malloc;
	t_r_value	params;
	t_r_value	params_args;
	t_r_value	texture;
	t_r_value	texture_args;
}	t_error;

typedef struct s_d_pos
{
	double	x;
	double	y;
}	t_d_pos;

typedef struct s_i_pos
{
	int	x;
	int	y;
}	t_i_pos;

typedef struct s_l_pos
{
	long int	x;
	long int	y;
}	t_l_pos;

typedef struct s_line
{
	t_d_pos	begin;
	t_d_pos	end;
}	t_line;

typedef struct s_mlx_texture
{
	void		*ptr;
	char		*buff;
	int			bpp;
	int			endian;
	int			size_line;
	t_i_pos		len;
}	t_mlx_texture;

typedef struct s_ray
{
	int				nbr;
	int				nbr_ray;
	int				depth_of_field;
	int				bit_prec;
	int				text_size;
	int				raycast_cell_size;
	int				raycast_player_size;
	t_bool			hit;
	t_l_pos			max;
	t_d_pos			pos;
	t_d_pos			offset;
	t_d_pos			save;
	t_d_pos			t;
	float			angle;
	float			a_tan;
	float			n_tan;
	float			ty_step;
	float			ty_offset;
	int				t_height;
	double			dist;
	t_mlx_texture	*img_use;
}	t_ray;

typedef struct s_mlx_textures
{
	t_mlx_texture	north;
	t_mlx_texture	south;
	t_mlx_texture	west;
	t_mlx_texture	east;
	t_mlx_texture	raycast_wall;
	t_mlx_texture	raycast_void;
	t_mlx_texture	raycast_player;
	t_mlx_texture	scene;
}	t_mlx_textures;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	void			*win_raycasting;
	t_i_pos			screen;
	t_mlx_textures	textures;
}	t_mlx;

typedef struct s_file
{
	int			fd;
	int			err_no;
	char		*path;
}	t_file;

typedef struct s_textures
{
	t_int4			floor;
	t_int4			ceiling;
	t_file			north_file;
	t_file			south_file;
	t_file			west_file;
	t_file			east_file;
}	t_textures;

typedef struct s_map
{
	t_file		file;
	t_l_pos		size;
	char		**matrix;
}	t_map;

typedef struct s_parse
{
	t_map		map;
	t_textures	textures;
}	t_parse;

typedef struct s_move
{
	t_bool	up;
	t_bool	down;
	t_bool	left;
	t_bool	right;
	t_bool	left_angle;
	t_bool	right_angle;
}	t_move;

typedef struct s_player
{
	t_d_pos	pos;
	t_d_pos	delta;
	float	angle;
	t_move	movement;
}	t_player;

typedef struct s_main
{
	t_parse		parse;
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	int			cursor;
	t_error		err;
}	t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// dataset/free/config.c
void			free_config(t_main *config);

// dataset/free/file.c
void			close_file(int fd);
void			free_file(t_file *file);

// dataset/free/mlx.c
void			free_mlx(t_mlx *mlx, t_error err);
void			free_mlx_texture(void *mlx, t_mlx_texture *text);
void			free_mlx_textures(t_mlx *mlx);

// dataset/free/mlx.hook.c
int				end_hook(t_mlx *mlx);

// dataset/free/parse.c
void			free_parse(t_parse *parse);

// dataset/free/texture.c
void			free_textures(t_textures *textures);

// dataset/init/config.c
void			init_config(t_main *config);

// dataset/init/file.c
void			init_file(t_file *file);
void			set_file(t_file *file, char *path, int fd);

// dataset/init/mlx.c
t_r_value		init_mlx(t_main *config);
void			init_mlx_texture(t_mlx_texture *text);
void			init_mlx_textures(t_mlx_textures *textures);
void			init_mlx_window(t_mlx *mlx, t_error *err);

// dataset/init/mlx.hook.c
int				key_press(int key_code, t_main *config);
int				key_release(int key_code, t_main *config);
t_bool			is_movement_key(int key_code);
void			init_mlx_hook(t_main *config);
void			set_movement(t_move *movement, int key_code, t_bool value);

// dataset/init/parse.c
void			init_parse(t_parse *parse);

// dataset/init/player.c
float			get_player_angle(char player_char);
void			get_player_pos(t_map map, t_player *player, int text_size);
void			init_player(t_player *player);

// dataset/init/rendering.c
t_r_value		init_rendering(t_main *config);
t_r_value		start_rendering(t_main *config);

// dataset/init/texture.c
void			init_textures(t_textures *texture);

// debug/error.c
void			debug_print_errn(t_error *err);
void			debug_print_errn_binary(const char *title, t_int64 to_bin);
void			debug_print_error(int mode, void *ptr);

// debug/map.c
void			debug_print_coord_checked(t_i_pos pos, char **map);

// debug/parsing.c
void			debug_print_map_size(t_map *map);
void			debug_print_parse(int mode, void *ptr);
void			debug_print_splitted(char **splitted);
void			debug_print_surrounded(char **splitted);

// debug/print.c
void			debug_print(int mode, void *ptr);

// debug/ray.c
void			debug_print_ray(int mode, void *ptr);
void			debug_print_ray_info(char *title, t_ray ray);

// debug/render.c
void			debug_print_key(int key_code);
void			debug_print_player_stat(t_player *player);
void			debug_print_render(int mode, void *ptr);
void			debug_print_screen_size(void *ptr);

// debug/render.line.c
void			debug_print_line_pos(t_line *line);

// error/print/entry.c
t_r_value		error_print(t_error err, t_main *config);
t_size			ft_put_padded(int fd, t_size lvl);
t_size			ft_put_padded_str(int fd, t_size lvl, const char *str);

// error/print/error_no_print.c
void			print_errno(int err_no, char *filename);

// error/print/malloc.c
void			error_print_malloc(t_r_value return_value);

// error/print/params.c
void			error_print_base(t_r_value params, int err_no);
void			error_print_params(t_error err, t_parse parse);
void			error_print_params_map(t_r_value params);

// error/print/params.color.c
void			error_print_params_color_format(t_r_value return_value);
void			error_print_params_color_non_numeric(t_r_value return_value);
void			error_print_params_color_wrong_number(t_r_value return_value);
void			error_print_params_wrong_color(t_error err);

// error/print/params.known.c
void			error_print_params_already_provided(t_r_value return_value);
void			error_print_params_have_empty(t_r_value return_value);
void			error_print_params_known(t_error err, t_parse parse);
void			error_print_params_wrong_path(t_r_value return_value, t_parse parse);
void			error_print_params_wrong_sep(t_r_value return_value);

// error/print/texture.c
void			error_print_texture(t_error err);

// error/print/texture.known.c
void			error_print_texture_known(t_error err);
void			error_print_texture_load(t_error err);
void			error_print_texture_window(t_error err);

// error/set/entry.c
t_r_value		set_error(t_error *err, unsigned char mode, t_r_value return_value);
t_r_value		set_error_known(t_error *err, int mode, t_r_value err_no, int type);
t_r_value		set_error_known_params(t_error *err, t_r_value err_no, int type);
t_r_value		set_error_known_texture(t_error *err, t_r_value err_no, int type);

// error/set/params.c
void			set_error_already_provided(int type, t_r_value *return_value);
void			set_error_have_empty(int type, t_r_value *return_value);
void			set_error_wrong_color(t_r_value err_no, int type, t_r_value *param_args);
void			set_error_wrong_path(int type, t_r_value *return_value);
void			set_error_wrong_sep(int type, t_r_value *return_value);

// error/set/texture.c
t_r_value		set_error_mlx_texture(t_param_type type, t_r_value *return_value);
t_r_value		set_error_mlx_window(t_param_type type, t_r_value *return_value);

// error/utils.c
t_bool			have_error(t_error err, int mode);
void			init_error(t_error *err);

// main.c

// parsing/dup_map_squared.c
char			**dup_map_squared(t_map map, int offset);
char			*dup_map_get_line(int width, char *line, int offset);
int				dup_map_get_surrounding(char **dup, int offset, t_map map);

// parsing/entry.c
int				parse_file(t_error *err, t_parse *parse, char *filename);
int				parse_file_name(t_error *err, char *filename);
t_r_value		parse_entry(t_error *err, char *filename, t_parse *parse);

// parsing/ft_cub3d_split.c
char			**ft_cub3d_split(char *str, char delim);
char			**ft_cub3d_split_get_words(char *str, char delim, int len_tab);
char			*ft_cub3d_get_word(char **str, char delim);

// parsing/line/color.c
int				check_line_color(t_error *err, char *ptr, int type, t_parse *parse);
int				parse_line_color(t_error *err, char *line, int type, t_parse *parse);

// parsing/line/entry.c
char			*parse_get_line(t_error *err, int file);
int				get_line_type(char *line);
int				is_good_line(t_error *err, char *line, t_parse *parse);
int				parse_line(t_error *err, char **line, t_parse *parse);
t_bool			is_line_already_taken(int already_taken, int line_type);

// parsing/line/texture.c
t_bool			ft_is_space(const char c);
t_r_value		parse_line_text(t_error *err, char *line, int type, t_parse *parse);

// parsing/map/check.surrounded.c
t_bool			check_is_surrounded_char_4(t_i_pos pos, char **map);
t_bool			check_is_surrounded_char_8(t_i_pos pos, char **map);
t_bool			check_is_surrounded_map(t_error *err, t_map *map);

// parsing/map/content.c
int				check_map_content(t_map *map, t_error *err);
int				check_map_player_char(t_map map, t_error *err);
t_bool			check_map_new_line(t_map map);
t_bool			check_map_wrong_char(t_map map);

// parsing/map/entry.c
t_bool			get_map(t_error *err, t_parse *parse);
t_bool			get_map_end(t_error *err, char **tmp_joined, t_parse *parse);
t_r_value		parse_map(t_error *err, t_parse *parse);

// parsing/params.c
t_bool			parse_file_is_empty(t_error *err, char **line, int fd);
t_r_value		parse_file_params(t_error *err, t_parse *parse);

// parsing/utils.1.c
int				check_permission(char *filename);
t_bool			map_char_is_player(char c);
void			get_map_size(t_map *map);

// rendering/draw/fov.c
void			draw_fov(t_main *config);

// rendering/draw/frame.c
int				draw_frame(t_main *config);
void			do_moving(t_main *config);

// rendering/draw/hit.c
void			draw_ray_hit(t_main *config);

// rendering/draw/line.c
t_line			get_line(t_d_pos begin, t_d_pos end);
void			draw_line(void *mlx_ptr, void *win_ptr, t_line line, int color);

// rendering/draw/raycast.c
void			draw_map(t_main *config);
void			draw_map_point(t_main *config, char current_cell, int y, int x);
void			draw_player_angle(t_main *config);
void			draw_player_pos(t_main *config);
void			draw_raycast(t_main *config);

// rendering/draw/scene.c
void			draw_background(t_int4 floor, t_int4 ceiling, t_mlx_texture *scene);
void			draw_scene(t_main *config);

// rendering/move/angle.c
void			adjust_delta(t_player *player, int text_size);
void			key_press_move_angle_left(t_player *player, int text_size);
void			key_press_move_angle_right(t_player *player, int text_size);

// rendering/move/dir.c
void			key_press_move_down(t_player *player);
void			key_press_move_left(t_player *player, int text_size);
void			key_press_move_right(t_player *player, int text_size);
void			key_press_move_up(t_player *player);

// rendering/raycast/cast.c
void			cast_ray_entry(t_main *config);
void			cast_rays(t_main *config);
void			choose_ray(t_main *config);

// rendering/raycast/get_text.c
void			fix_fisheyes(t_ray *ray, t_player player);
void			get_text(t_main *config);
void			push_buff_pixel_text(t_ray *ray, t_mlx_texture *scene);
void			push_buff_scene_color(t_ray *ray, t_mlx_texture *scene, int counter);
void			set_texture_height(t_ray *ray, t_mlx_texture scene);

// rendering/raycast/horizontal.c
void			cast_ray_down(t_ray *ray, t_player player);
void			cast_ray_horizontal(t_ray *ray, t_player player, t_map map);
void			cast_ray_up(t_ray *ray, t_player player);

// rendering/raycast/vertical.c
void			cast_ray_left(t_ray *ray, t_player player);
void			cast_ray_right(t_ray *ray, t_player player);
void			cast_ray_vertical(t_ray *ray, t_player player, t_map map);

// rendering/texture/load.c
t_r_value		load_scene(t_main *config);
t_r_value		load_texture(t_mlx_texture *text, char *file_path, void *mlx);
t_r_value		load_textures(t_main *config);

// rendering/texture/load.size.c
unsigned char	get_bit_prec(int lowest);
void			get_highest_size(t_i_pos *lowest, t_mlx_texture text);
void			get_raycast_size(t_main *config);
void			get_textures_size(t_main *config);

// rendering/utils.1.c
double			get_a_tan(double ray_angle);
double			get_dist(t_d_pos begin, t_d_pos end);
double			get_n_tan(double ray_angle);
t_bool			ray_hit(t_ray *ray, t_map map, int to_add);
void			increase_offset(t_ray *ray);

// rendering/utils.2.c
float			get_ratio(float nbr, t_ray ray);
int				check_in_img(t_ray ray, int point);
void			ft_put_pixel(int x, int y, t_mlx_texture *image, t_int4 color);

/* ########################################################################## */

#endif
