# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/23 06:11:11 by brda-sil         ###   ########.fr        #
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
VERSION				:= 1.2.0
$(eval export MAIN=1)

ifeq ($(findstring bonus,$(MAKECMDGOALS)),bonus)
BONUS				:= 1
else
ifeq ($(findstring re_bonus,$(MAKECMDGOALS)),re_bonus)
BONUS				:= 1
else
ifeq ($(findstring run_bonus,$(MAKECMDGOALS)),run_bonus)
BONUS				:= 1
else
BONUS				:= 0
endif
endif
endif

ifneq ($(PADDING),60)
PADDING				:= 60
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
SRC_C_MANDATORY		:= src/mandatory/dataset/free/config.c \
					   src/mandatory/dataset/free/file.c \
					   src/mandatory/dataset/free/mlx.c \
					   src/mandatory/dataset/free/mlx.hook.c \
					   src/mandatory/dataset/free/parse.c \
					   src/mandatory/dataset/free/texture.c \
					   src/mandatory/dataset/init/config.c \
					   src/mandatory/dataset/init/file.c \
					   src/mandatory/dataset/init/mlx.c \
					   src/mandatory/dataset/init/mlx.hook.c \
					   src/mandatory/dataset/init/parse.c \
					   src/mandatory/dataset/init/player.c \
					   src/mandatory/dataset/init/rendering.c \
					   src/mandatory/dataset/init/texture.c \
					   src/mandatory/debug/error.c \
					   src/mandatory/debug/map.c \
					   src/mandatory/debug/parsing.c \
					   src/mandatory/debug/print.c \
					   src/mandatory/debug/ray.c \
					   src/mandatory/debug/render.c \
					   src/mandatory/debug/render.line.c \
					   src/mandatory/error/print/entry.c \
					   src/mandatory/error/print/error_no_print.c \
					   src/mandatory/error/print/malloc.c \
					   src/mandatory/error/print/params.c \
					   src/mandatory/error/print/params.color.c \
					   src/mandatory/error/print/params.known.c \
					   src/mandatory/error/print/texture.c \
					   src/mandatory/error/print/texture.known.c \
					   src/mandatory/error/set/entry.c \
					   src/mandatory/error/set/params.c \
					   src/mandatory/error/set/texture.c \
					   src/mandatory/error/utils.c \
					   src/mandatory/main.c \
					   src/mandatory/parsing/dup_map_squared.c \
					   src/mandatory/parsing/entry.c \
					   src/mandatory/parsing/ft_cub3d_split.c \
					   src/mandatory/parsing/line/color.c \
					   src/mandatory/parsing/line/entry.c \
					   src/mandatory/parsing/line/texture.c \
					   src/mandatory/parsing/map/check.surrounded.c \
					   src/mandatory/parsing/map/content.c \
					   src/mandatory/parsing/map/entry.c \
					   src/mandatory/parsing/params.c \
					   src/mandatory/parsing/utils.1.c \
					   src/mandatory/rendering/draw/fov.c \
					   src/mandatory/rendering/draw/frame.c \
					   src/mandatory/rendering/draw/hit.c \
					   src/mandatory/rendering/draw/line.c \
					   src/mandatory/rendering/draw/raycast.c \
					   src/mandatory/rendering/draw/scene.c \
					   src/mandatory/rendering/move/angle.c \
					   src/mandatory/rendering/move/dir.c \
					   src/mandatory/rendering/raycast/cast.c \
					   src/mandatory/rendering/raycast/get_text.c \
					   src/mandatory/rendering/raycast/horizontal.c \
					   src/mandatory/rendering/raycast/vertical.c \
					   src/mandatory/rendering/texture/load.c \
					   src/mandatory/rendering/texture/load.size.c \
					   src/mandatory/rendering/utils.1.c \
					   src/mandatory/rendering/utils.2.c

SRC_C_BONUS			:= src/bonus/dataset/free/config.c \
					   src/bonus/dataset/free/file.c \
					   src/bonus/dataset/free/mlx.c \
					   src/bonus/dataset/free/mlx.hook.c \
					   src/bonus/dataset/free/parse.c \
					   src/bonus/dataset/free/texture.c \
					   src/bonus/dataset/init/config.c \
					   src/bonus/dataset/init/file.c \
					   src/bonus/dataset/init/mlx.c \
					   src/bonus/dataset/init/mlx.hook.c \
					   src/bonus/dataset/init/mlx.hook.mouse.c \
					   src/bonus/dataset/init/parse.c \
					   src/bonus/dataset/init/player.c \
					   src/bonus/dataset/init/rendering.c \
					   src/bonus/dataset/init/texture.c \
					   src/bonus/debug/error.c \
					   src/bonus/debug/map.c \
					   src/bonus/debug/parsing.c \
					   src/bonus/debug/print.c \
					   src/bonus/debug/ray.c \
					   src/bonus/debug/render.c \
					   src/bonus/debug/render.line.c \
					   src/bonus/error/print/entry.c \
					   src/bonus/error/print/error_no_print.c \
					   src/bonus/error/print/malloc.c \
					   src/bonus/error/print/params.c \
					   src/bonus/error/print/params.color.c \
					   src/bonus/error/print/params.known.c \
					   src/bonus/error/print/texture.c \
					   src/bonus/error/print/texture.known.c \
					   src/bonus/error/set/entry.c \
					   src/bonus/error/set/params.c \
					   src/bonus/error/set/texture.c \
					   src/bonus/error/utils.c \
					   src/bonus/main.c \
					   src/bonus/parsing/dup_map_squared.c \
					   src/bonus/parsing/entry.c \
					   src/bonus/parsing/ft_cub3d_split.c \
					   src/bonus/parsing/line/color.c \
					   src/bonus/parsing/line/entry.c \
					   src/bonus/parsing/line/texture.c \
					   src/bonus/parsing/map/check.door.surrounded.c \
					   src/bonus/parsing/map/check.surrounded.c \
					   src/bonus/parsing/map/content.c \
					   src/bonus/parsing/map/entry.c \
					   src/bonus/parsing/params.c \
					   src/bonus/parsing/utils.1.c \
					   src/bonus/rendering/draw/fov.c \
					   src/bonus/rendering/draw/frame.c \
					   src/bonus/rendering/draw/hit.c \
					   src/bonus/rendering/draw/line.c \
					   src/bonus/rendering/draw/minimap.c \
					   src/bonus/rendering/draw/raycast.c \
					   src/bonus/rendering/draw/scene.c \
					   src/bonus/rendering/move/angle.c \
					   src/bonus/rendering/move/dir.c \
					   src/bonus/rendering/raycast/cast.c \
					   src/bonus/rendering/raycast/get_text.c \
					   src/bonus/rendering/raycast/horizontal.c \
					   src/bonus/rendering/raycast/vertical.c \
					   src/bonus/rendering/texture/load.c \
					   src/bonus/rendering/texture/load.size.c \
					   src/bonus/rendering/utils.1.c \
					   src/bonus/rendering/utils.2.c

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
.PHONY:		ft_helper

.DEFAULT:	all

all:			setup $(TARGET)
	$(PRINTF) "$$usage"

bonus:			setup $(TARGET_BONUS)
	$(PRINTF) "$$usage"

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

setup:					call_logo $(OBJ_SUBDIR) $(BIN_DIR) ft_helper
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

ft_helper:
ifeq ($(DEBUG),1)
	@./scripts/ft_helper/ft_helper
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

re_bonus:				fclean bonus

run:					re
	./$(TARGET) ./rsc/map/test.1.cub
	
run_bonus:				re_bonus
	./$(TARGET_BONUS) ./rsc/map/test.1.cub

# **************************************************************************** #
