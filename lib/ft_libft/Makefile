# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2023/01/17 20:13:27 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config

VERSION				:= 1.0.0
MULTIPLE			:= 0

ifeq ($(findstring integer,$(MAKECMDGOALS)),integer)
INTEGER			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
endif
ifeq ($(findstring string,$(MAKECMDGOALS)),string)
STRING			:= 1
MULTIPLE		:= 1
# dependecies
INTEGER			:= 1
CHECK			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring memory,$(MAKECMDGOALS)),memory)
MEMORY			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
endif
ifeq ($(findstring check,$(MAKECMDGOALS)),check)
CHECK			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring list,$(MAKECMDGOALS)),list)
LIST			:= 1
MULTIPLE		:= 1
endif
ifeq ($(findstring print,$(MAKECMDGOALS)),print)
PRINT			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
MEMORY			:= 1
INTEGER			:= 1
endif
ifeq ($(findstring input,$(MAKECMDGOALS)),input)
INPUT			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring random,$(MAKECMDGOALS)),random)
RANDOM			:= 1
MULTIPLE		:= 1
# dependecies
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(findstring linux,$(MAKECMDGOALS)),linux)
LINUX			:= 1
MULTIPLE		:= 1
# dependecies
RANDOM			:= 1
CHECK			:= 1
endif
ifeq ($(findstring ipv4,$(MAKECMDGOALS)),ipv4)
NET_IPV4		:= 1
MULTIPLE		:= 1
# dependecies
PRINT			:= 1
INTEGER			:= 1
CHECK			:= 1
STRING			:= 1
MEMORY			:= 1
endif
ifeq ($(MULTIPLE), 0)
ALL				:= 1
endif

TARGET				:= libft.a
CFLAGS				:= -Wall -Wextra -pthread
RM					:= rm -rf
CC					:= gcc
MAKE				:= make -C
$(eval export MAIN=1)

ifeq ($(PADDING),)
PADDING				:= 35
endif

ifeq ($(DEBUG),)
CFLAGS				+= -Werror
else
CFLAGS				+= -g3
endif

# DIR
SRC_DIR				:= src
OBJ_DIR				:= obj
OBJ_SUBDIR			:= $(sort $(shell find $(SRC_DIR) -type d | \
										sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_DIR				:= -Iinc
# LIB DIR
CFLAGS				+= $(INC_DIR)

# MULTIPLE PART SOURCE INCLUDE

## add base of SRC_*

### INTEGER
SRC_INT				:= integer/ft_get_base.c \
					   integer/ft_int4_chg.c \
					   integer/ft_int4_comp.c \
					   integer/ft_int4_dcomp.c \
					   integer/ft_int4_dec.c \
					   integer/ft_int4_inc.c \
					   integer/ft_itoa.c \
					   integer/ft_itoa_base.c \
					   integer/ft_ltoa.c \
					   integer/ft_ltoa_base.c \
					   integer/ft_nbrlen.c \
					   integer/ft_nbrlen_base.c \
					   integer/ft_rev_int.c \
					   integer/ft_utoa.c \
					   integer/ft_utoa_base.c

### STRING
SRC_STR				:= string/ft_atoi.c \
					   string/ft_atoi_base.c \
					   string/ft_atoll.c \
					   string/ft_atoll_base.c \
					   string/ft_atou.c \
					   string/ft_atou_base.c \
					   string/ft_get_words.c \
					   string/ft_patoi.c \
					   string/ft_patoi_base.c \
					   string/ft_patoll.c \
					   string/ft_patoll_base.c \
					   string/ft_patou.c \
					   string/ft_patou_base.c \
					   string/ft_split.c \
					   string/ft_splitb.c \
					   string/ft_strcat.c \
					   string/ft_strcchr.c \
					   string/ft_strchr.c \
					   string/ft_strclr.c \
					   string/ft_strcmp.c \
					   string/ft_strcpy.c \
					   string/ft_strcspn.c \
					   string/ft_strdel.c \
					   string/ft_strdup.c \
					   string/ft_striteri.c \
					   string/ft_strjoin.c \
					   string/ft_strlcat.c \
					   string/ft_strlcpy.c \
					   string/ft_strlen.c \
					   string/ft_strmapi.c \
					   string/ft_strncat.c \
					   string/ft_strncmp.c \
					   string/ft_strncpy.c \
					   string/ft_strnstr.c \
					   string/ft_strrchr.c \
					   string/ft_strspn.c \
					   string/ft_strtok.c \
					   string/ft_strtrim.c \
					   string/ft_substr.c \
					   string/ft_tolower.c \
					   string/ft_toupper.c

### MEMORY
SRC_MEM				:= memory/ft_bzero.c \
					   memory/ft_calloc.c \
					   memory/ft_free_char_pp.c \
					   memory/ft_memchr.c \
					   memory/ft_memcmp.c \
					   memory/ft_memcpy.c \
					   memory/ft_memjoin.c \
					   memory/ft_memmove.c \
					   memory/ft_memnchr.c \
					   memory/ft_memset.c

### CHECK
SRC_CHK				:= check/ft_is_str.c \
					   check/ft_isalnum.c \
					   check/ft_isalpha.c \
					   check/ft_isascii.c \
					   check/ft_isblank.c \
					   check/ft_isdigit.c \
					   check/ft_isgoodi.c \
					   check/ft_isgoodll.c \
					   check/ft_isgoodu.c \
					   check/ft_isprint.c \
					   check/ft_isspace.c

### LIST
SRC_LST				:= list/ft_lstadd_back.c \
					   list/ft_lstadd_front.c \
					   list/ft_lstclear.c \
					   list/ft_lstdelone.c \
					   list/ft_lstiter.c \
					   list/ft_lstlast.c \
					   list/ft_lstmap.c \
					   list/ft_lstnew.c \
					   list/ft_lstsize.c

### PRINT
SRC_PRT				:= print/ft_error.c \
					   print/ft_printf.c \
					   print/ft_printf_fd.c \
					   print/ft_putchar_fd.c \
					   print/ft_putendl_fd.c \
					   print/ft_puthex_fd.c \
					   print/ft_putnbr_base_fd.c \
					   print/ft_putnbr_fd.c \
					   print/ft_putstr_fd.c \
					   print/ft_putunbr_fd.c

### INPUT
SRC_INP				:= input/ft_get_next_line.c

### RANDOM
SRC_RDM				:= random/ft_randint.c \
					   random/ft_tmpfile.c

### LINUX
SRC_LNX				:= linux/ft_getgid.c \
					   linux/ft_getuid.c \
					   linux/ft_iscdable.c \
					   linux/ft_isdir.c \
					   linux/ft_isexec.c \
					   linux/ft_isfile.c

### NETWORK

#### IPV4
SRC_NET_IPV4		:= network/ipv4/ft_ipstr.c \
					   network/ipv4/ft_putip_fd.c

## if all, add all base to SRC_C
ifeq ($(ALL),1)
SRC_C				+= $(SRC_INT)
SRC_C				+= $(SRC_STR)
SRC_C				+= $(SRC_MEM)
SRC_C				+= $(SRC_CHK)
SRC_C				+= $(SRC_LST)
SRC_C				+= $(SRC_PRT)
SRC_C				+= $(SRC_INP)
SRC_C				+= $(SRC_RDM)
SRC_C				+= $(SRC_LNX)
SRC_C				+= $(SRC_NET_IPV4)

## add base part to SRC_C
else
ifeq ($(INTEGER),1)
SRC_C			+= $(SRC_INT)
endif
ifeq ($(STRING),1)
SRC_C			+= $(SRC_STR)
endif
ifeq ($(MEMORY),1)
SRC_C			+= $(SRC_MEM)
endif
ifeq ($(CHECK),1)
SRC_C			+= $(SRC_CHK)
endif
ifeq ($(PRINT),1)
SRC_C			+= $(SRC_PRT)
endif
ifeq ($(LIST),1)
SRC_C			+= $(SRC_LST)
endif
ifeq ($(INPUT),1)
SRC_C			+= $(SRC_INP)
endif
ifeq ($(RANDOM),1)
SRC_C			+= $(SRC_RDM)
endif
ifeq ($(LINUX),1)
SRC_C			+= $(SRC_LNX)
endif
ifeq ($(NET_IPV4),1)
SRC_C			+= $(SRC_NET_IPV4)
endif
endif

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))


#  Bash Color / unicode char

get_random			= \033[38;5;$(shell seq 0 256 | shuf | head -n1)m
green				:= \033[38;5;82m
blue				:= \033[38;5;75m
red					:= \033[38;5;196m
orange				:= \033[38;5;214m

blinking			:= \033[5m
reset				:= \033[0m

font_color			:= $(blue)
bold				:= $(green)
ascii_color			:= $(bold)

green_plus			:= $(font_color)[$(green)+$(font_color)]$(reset)
red_minus			:= $(font_color)[$(red)-$(font_color)]$(reset)
orange_star			:= $(font_color)[$(orange)*$(font_color)]$(reset)
blinking_arrow		:= $(blinking)$(font_color)->$(reset)

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
███████╗████████╗     ██╗     ██╗██████╗ ███████╗████████╗
██╔════╝╚══██╔══╝     ██║     ██║██╔══██╗██╔════╝╚══██╔══╝
█████╗     ██║        ██║     ██║██████╔╝█████╗     ██║
██╔══╝     ██║        ██║     ██║██╔══██╗██╔══╝     ██║
██║        ██║        ███████╗██║██████╔╝██║        ██║
╚═╝        ╚═╝        ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝
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
$(orange_star) $(bold)modulable$(font_color) ft_library
	You can make $(bold)any$(font_color) parts into the archive of the library.
		$(bold)exemple$(font_color):
			make $(bold)string$(font_color)
			make $(bold)string integer$(font_color)
			make re $(bold)string integer$(font_color)

	The following parts are available (non-exhaustive list of function):
		$(bold)integer$(font_color)\tmanipulate integer
			$(bold)ft_itoa$(font_color), $(bold)ft_nbrlen$(font_color), \
$(bold)ft_int4_comp

		string$(font_color)\tmanipulate string
			$(bold)ft_atoi$(font_color), $(bold)ft_strlen$(font_color), \
$(bold)ft_strjoin

		memory$(font_color)\tmanipulate / allocate memory
			$(bold)ft_calloc$(font_color), $(bold)ft_memchr$(font_color), \
$(bold)ft_memjoin

		check$(font_color)\tcheck something
			$(bold)ft_isalnum$(font_color), $(bold)ft_isgoodi

		list$(font_color)\twork with linked list
			$(bold)ft_lstnew$(font_color), $(bold)ft_lstadd_back

		print$(font_color)\tprint something
			$(bold)ft_printf$(font_color), $(bold)ft_printf_fd$(font_color),\
$(bold)ft_putchar

		input$(font_color)\twork with input
			$(bold)ft_get_next_line

		random$(font_color)\twork with randomness
			$(bold)ft_randint$(font_color), $(bold)ft_tmpfile

		linux$(font_color)\twork with linux
			$(bold)ft_iscdable$(font_color), $(bold)ft_getuid$(font_color), \
$(bold)ft_getgid$(font_color)

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

# rules that does not create file
.PHONY:					clean fclean setup call_logo $(OBJ_SUBDIR)

all:					setup $(TARGET)
	@printf "$$usage"

integer:	setup $(TARGET)
	@printf ""

string:		setup $(TARGET)
	@printf ""

memory:		setup $(TARGET)
	@printf ""

check:		setup $(TARGET)
	@printf ""

list:		setup $(TARGET)
	@printf ""

print:		setup $(TARGET)
	@printf ""

input:		setup $(TARGET)
	@printf ""

random:		setup $(TARGET)
	@printf ""

linux:		setup $(TARGET)
	@printf ""

ipv4:		setup $(TARGET)
	@printf ""

$(TARGET):				$(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@ar rcs $(TARGET) $(OBJ_C)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

setup:					call_logo $(OBJ_SUBDIR)
ifeq ($(DEBUG),1)
	@printf "$(orange_star) $(font_color)Info$(reset)\n"
	@printf "   $(orange_star) $(bold)Switch$(reset)\n"
	@printf "      $(orange_star) $(font_color)INTEGER $(bold)%d$(reset)\n" $(INTEGER)
	@printf "      $(orange_star) $(font_color)STRING $(bold)%d$(reset)\n" $(STRING)
	@printf "      $(orange_star) $(font_color)MEMORY $(bold)%d$(reset)\n" $(MEMORY)
	@printf "      $(orange_star) $(font_color)CHECK $(bold)%d$(reset)\n" $(CHECK)
	@printf "      $(orange_star) $(font_color)LIST $(bold)%d$(reset)\n" $(LIST)
	@printf "      $(orange_star) $(font_color)PRINT $(bold)%d$(reset)\n" $(PRINT)
	@printf "      $(orange_star) $(font_color)INPUT $(bold)%d$(reset)\n" $(INPUT)
	@printf "      $(orange_star) $(font_color)RANDOM $(bold)%d$(reset)\n" $(RANDOM)
	@printf "      $(orange_star) $(font_color)LINUX $(bold)%d$(reset)\n" $(LINUX)
	@printf "      $(orange_star) $(font_color)NET_IPV4 $(bold)%d$(reset)\n" $(NET_IPV4)
	@printf "\n"
	@printf "      $(orange_star) $(font_color)ALL $(bold)%d$(reset)\n" $(ALL)
	@printf "   $(orange_star) $(font_color)TARGET $(bold)%s$(reset)\n" $(TARGET)
	@printf "   $(orange_star) $(bold)SRC_C$(reset)\n"
	@printf "      $(orange_star) $(font_color)%s$(reset)\n" $(SRC_C)
	@printf "   $(orange_star) $(bold)OBJ_C$(reset)\n"
	@printf "      $(orange_star) $(font_color)%s$(reset)\n" $(OBJ_C)
	@printf "$(orange_star) $(font_color)Building$(reset)\n"
endif

help:
	@printf "$$usage"

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

clean:
ifneq ($(wildcard $(OBJ_DIR)),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)
endif

fclean:					clean
ifneq ($(wildcard $(TARGET)),)
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)
endif

clean_test:
	@printf "$(red_minus) $(font_color)Deleting $(bold)./test_run$(reset)\n"
	@$(RM) ./test_run

test_run:				clean_test $(TARGET)
	@printf "$(green_plus) $(font_color)Create test file from $(bold)$(TEST)$(reset)\n"
	@$(CC) $(CFLAGS) $(TEST) $(TARGET) -o test_run
	./test_run $(TEST_ARGS)

re:						fclean all

# **************************************************************************** #
