# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/18 11:12:29 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS				:= -Wall -Wextra
TARGET				:= cub3D
TARGET_BONUS		:= cub3D_bonus
RM					:= rm -rf
CC					:= gcc
PRINTF				:= @printf
MAKE				:= make -C
VERSION				:= 1.1.0
$(eval export MAIN=1)

ifeq ($(findstring bonus,$(MAKECMDGOALS)),bonus)
BONUS				:= 1
else
BONUS				:= 0
endif

ifneq ($(PADDING),45)
PADDING				:= 45
endif

ifeq ($(DEBUG),)
CFLAGS				+= -Werror
else
CFLAGS				+= -g3
endif

# DIR
BIN_DIR				:=
SRC_DIR				:= src
LIB_DIR				:= lib
OBJ_DIR				:= obj
OBJ_SUBDIR			:= $(sort $(shell find $(SRC_DIR) -type d | \
											sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_TMP				:= inc \
					   $(LIB_DIR)/ft_libft/inc \
					   $(LIB_DIR)/minilibx-linux
INC_DIR				:= $(addprefix -I,$(INC_TMP))

# LIB
LIBFT				:= $(LIB_DIR)/ft_libft/libft.a
MINI_LIBX			:= $(LIB_DIR)/minilibx-linux/libmlx_Linux.a

LDFLAGS				:= -Llib/minilibx-linux -L/usr/lib -lXext -lX11 -lm -lbsd -lz

# SRC
SRC_C_MANDATORY		:= src/mandatory/draw/scene.c \
					   src/mandatory/draw/text.c \
					   src/mandatory/error/error.c \
					   src/mandatory/error/print.c \
					   src/mandatory/error/print.malloc.c \
					   src/mandatory/error/print.params.c \
					   src/mandatory/error/print.params.color.c \
					   src/mandatory/error/print.params.known.c \
					   src/mandatory/error/print.texture.c \
					   src/mandatory/error/print.texture.known.c \
					   src/mandatory/error/set.c \
					   src/mandatory/error/set.params.c \
					   src/mandatory/error/set.texture.c \
					   src/mandatory/main.c \
					   src/mandatory/mlx/mlx.free.c \
					   src/mandatory/mlx/mlx.hook.c \
					   src/mandatory/mlx/mlx.init.c \
					   src/mandatory/mlx/move.angle.c \
					   src/mandatory/mlx/move.dir.c \
					   src/mandatory/parse/map/check.c \
					   src/mandatory/parse/map/check.surrounded.c \
					   src/mandatory/parse/map/entry.c \
					   src/mandatory/parse/parse.entry.c \
					   src/mandatory/parse/parse.file.c \
					   src/mandatory/parse/parse.line.c \
					   src/mandatory/parse/parse.line.color.c \
					   src/mandatory/parse/parse.line.texture.c \
					   src/mandatory/parse/utils.1.c \
					   src/mandatory/ray/cast.c \
					   src/mandatory/ray/horizontal.c \
					   src/mandatory/ray/utils.1.c \
					   src/mandatory/ray/vertical.c \
					   src/mandatory/struct/config.c \
					   src/mandatory/struct/file.c \
					   src/mandatory/struct/parsing.c \
					   src/mandatory/struct/player.c \
					   src/mandatory/struct/rendering.c \
					   src/mandatory/struct/texture.c \
					   src/mandatory/struct/texture.get_size.c \
					   src/mandatory/utils/file.c \
					   src/mandatory/utils/ft_cub3d_split.c \
					   src/mandatory/utils/ft_free_char_pointer.c \
					   src/mandatory/utils/get_line.c

SRC_C_BONUS			:= src/bonus/debug/debug.error_bonus.c \
					   src/bonus/debug/debug.map_bonus.c \
					   src/bonus/debug/debug.parsing_bonus.c \
					   src/bonus/debug/debug.ray_bonus.c \
					   src/bonus/debug/debug.render.line_bonus.c \
					   src/bonus/debug/debug.render_bonus.c \
					   src/bonus/debug/debug_bonus.c \
					   src/bonus/draw/line_bonus.c \
					   src/bonus/draw/ray_bonus.c \
					   src/bonus/draw/raycast_bonus.c \
					   src/bonus/draw/scene_bonus.c \
					   src/bonus/draw/text_bonus.c \
					   src/bonus/error/error_bonus.c \
					   src/bonus/error/print.malloc_bonus.c \
					   src/bonus/error/print.params.color_bonus.c \
					   src/bonus/error/print.params.known_bonus.c \
					   src/bonus/error/print.params_bonus.c \
					   src/bonus/error/print.texture.known_bonus.c \
					   src/bonus/error/print.texture_bonus.c \
					   src/bonus/error/print_bonus.c \
					   src/bonus/error/set.params_bonus.c \
					   src/bonus/error/set.texture_bonus.c \
					   src/bonus/error/set_bonus.c \
					   src/bonus/main_bonus.c \
					   src/bonus/mlx/mlx.free_bonus.c \
					   src/bonus/mlx/mlx.hook_bonus.c \
					   src/bonus/mlx/mlx_bonus.c \
					   src/bonus/mlx/move.angle_bonus.c \
					   src/bonus/mlx/move.dir_bonus.c \
					   src/bonus/parse/map/check.surrounded_bonus.c \
					   src/bonus/parse/map/check_bonus.c \
					   src/bonus/parse/map/entry_bonus.c \
					   src/bonus/parse/parse.entry_bonus.c \
					   src/bonus/parse/parse.file_bonus.c \
					   src/bonus/parse/parse.line.color_bonus.c \
					   src/bonus/parse/parse.line.texture_bonus.c \
					   src/bonus/parse/parse.line_bonus.c \
					   src/bonus/parse/utils.1_bonus.c \
					   src/bonus/ray/cast_bonus.c \
					   src/bonus/ray/horizontal_bonus.c \
					   src/bonus/ray/utils.1_bonus.c \
					   src/bonus/ray/vertical_bonus.c \
					   src/bonus/struct/config_bonus.c \
					   src/bonus/struct/file.utils_bonus.c \
					   src/bonus/struct/file_bonus.c \
					   src/bonus/struct/parsing_bonus.c \
					   src/bonus/struct/player_bonus.c \
					   src/bonus/struct/rendering_bonus.c \
					   src/bonus/struct/texture.get_size_bonus.c \
					   src/bonus/struct/texture_bonus.c \
					   src/bonus/utils/ft_cub3d_split_bonus.c \
					   src/bonus/utils/ft_free_char_pointer_bonus.c \
					   src/bonus/utils/get_line_bonus.c \
					   src/bonus/utils/get_ratio_bonus.c

# OBJ
ifeq ($(BONUS),1)
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C_BONUS:%.c=%.o))
else
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C_MANDATORY:%.c=%.o))
endif

# LIB DIR
CFLAGS			+= $(INC_DIR)
LIBS			:= $(LIBFT) $(MINI_LIBX)

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(green)
ascii_color		:= $(bold)

green_plus		:= $(font_color)[$(green)+$(font_color)]
red_minus		:= $(font_color)[$(red)-$(font_color)]
orange_star		:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow	:= $(blinking)$(font_color)->
#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
 ██████╗██╗   ██╗██████╗ ██████╗ ██████╗
██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝ █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝
$(reset)
endef
export ascii_art

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
$(orange_star) $(bold)$(TARGET)$(font_color): $(bold)needed_args \
$(font_color)[$(bold)optional_args$(font_color)]$(reset)
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation, $(bold)WARNING$(reset)
$(font_color)Version: $(bold)$(VERSION)$(reset)

endef
export usage

define make_dir
	@if [ ! -d $1 ]; then														\
		mkdir $1;																\
		printf "$(green_plus) $(font_color)Create dir $(bold)$1$(reset)\n";		\
	fi
endef
# **************************************************************************** #

# **************************************************************************** #
# Rules

.PHONY:		all
.PHONY:		clean
.PHONY:		fclean
.PHONY:		re
.PHONY:		clean_all
.PHONY:		fclean_all
.PHONY:		re_all
.PHONY:		setup
.PHONY:		lib
.PHONY:		call_logo

.DEFAULT:	all

all:			setup $(TARGET)
	@$(PRINTF) "$$usage"

bonus:			setup $(TARGET_BONUS)
	@$(PRINTF) ""

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@$(MAKE) lib/ft_libft all

$(MINI_LIBX):
	@$(MAKE) lib/minilibx-linux all

$(TARGET):				$(LIBFT) $(MINI_LIBX) $(OBJ_C)
	$(PRINTF) "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS) $(LDFLAGS)

$(TARGET_BONUS):		$(LIBFT) $(MINI_LIBX) $(OBJ_C)
	$(PRINTF) "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS) $(LDFLAGS)

setup:					call_logo $(OBJ_SUBDIR) $(BIN_DIR)
ifeq ($(DEBUG),1)
	$(PRINTF) "$(orange_star) $(font_color)Info$(reset)\n"
	$(PRINTF) "   $(orange_star) $(bold)Switch$(reset)\n"
	$(PRINTF) "      $(orange_star) $(font_color)BONUS $(bold)%d$(reset)\n" $(BONUS)
	$(PRINTF) "\n"
	$(PRINTF) "   $(orange_star) $(font_color)TARGET $(bold)%s$(reset)\n" $(TARGET)
ifeq ($(BONUS),1)
	$(PRINTF) "   $(orange_star) $(bold)SRC_C_BONUS$(reset)\n"
	$(PRINTF) "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C_BONUS)
else
	$(PRINTF) "   $(orange_star) $(bold)SRC_C_MANDATORY$(reset)\n"
	$(PRINTF) "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C_MANDATORY)
endif
	$(PRINTF) "   $(orange_star) $(bold)OBJ_C$(reset)\n"
	$(PRINTF) "      $(orange_star) $(font_color)%s$(reset)\n" $(OBJ_C)
	$(PRINTF) "$(orange_star) $(font_color)Building$(reset)\n"
endif

call_logo:
	$(PRINTF) "$(ascii_color)$$ascii_art"

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

clean_all:				clean
	$(MAKE) lib/ft_libft clean
	$(MAKE) lib/minilibx-linux clean

clean:
	$(PRINTF) "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean_all:				fclean
	@$(MAKE) lib/ft_libft fclean
	@$(MAKE) lib/minilibx-linux clean

fclean:					clean
	$(PRINTF) "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
	$(PRINTF) "$(red_minus) $(font_color)Deleting $(bold)$(TARGET_BONUS)$(reset)\n"
	@$(RM) $(TARGET_BONUS)

re_lib:
	@$(MAKE) lib/ft_libft re
	@$(MAKE) lib/minilibx-linux re

re:						fclean all

re_all:					re_lib re


# **************************************************************************** #
